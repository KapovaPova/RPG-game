// ©2023 JDSherbert. All rights reserved.

#include "Pathfinder.h"

#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>

// -------------------------
// Node Implementation
// -------------------------

// Constructor initializes coordinates and cost values
Node::Node(int _x, int _y)
    : x(_x)
    , y(_y)
    , f(0)
    , g(0)
    , h(0)
{
}

// Compare nodes by total cost (for priority queue)
bool Node::operator>(const Node& other) const
{
    return f > other.f;
}

// Equality check (same coordinates)
bool Node::operator==(const Node& other) const
{
    return x == other.x && y == other.y;
}

// -------------------------
// A* Pathfinding Algorithm
// -------------------------

std::vector<Node> FindPath(const std::vector<std::vector<char>>& graph, char char_empty, const Node& start, const Node& goal)
{
    // Possible movement directions: up, right, down, left
    const int directionX[] = {-1, 0, 1, 0};
    const int directionY[] = {0, 1, 0, -1};

    int rows = graph.size(); // y
    int cols = graph[0].size(); // x

    // Priority queue (min-heap) sorted by lowest f cost
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> openList;

    // Closed list: marks visited nodes
    std::vector<std::vector<bool>> closedList(rows, std::vector<bool>(cols, false));

    // gScore: best-known cost to reach each cell
    std::vector<std::vector<int>> gScore(rows, std::vector<int>(cols, INT_MAX));

    // Parent matrix: stores the node from which we arrived at each position
    std::vector<std::vector<Node>> parent(rows, std::vector<Node>(cols));

    // Initialize start node cost
    gScore[start.y][start.x] = 0;
    openList.push(start);

    // -------------------------
    // Main A* search loop
    // -------------------------
    while (!openList.empty())
    {
        // Get node with lowest f score
        Node current = openList.top();
        openList.pop();

        // Check if we've reached the goal
        if (current == goal)
        {
            // Reconstruct the path by backtracking through parents
            std::vector<Node> path;
            while (!(current == start))
            {
                path.push_back(current);
                current = parent[current.y][current.x];
            }
            path.push_back(start);

            // Reverse to get path from start → goal
            std::reverse(path.begin(), path.end());
            return path;
        }

        // Mark current node as closed (visited)
        closedList[current.y][current.x] = true;

        // Explore all 4 neighboring cells
        for (int i = 0; i < 4; ++i)
        {
            int newX = current.x + directionX[i];
            int newY = current.y + directionY[i];

            // Check grid boundaries and walkability
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && graph[newY][newX] == char_empty)
            {
                // Skip already processed (closed) cells
                if (closedList[newY][newX])
                    continue;

                // Tentative g cost (current cost + 1 for movement)
                int newG = gScore[current.y][current.x] + 1;

                // If we found a better path to this neighbor
                if (newG < gScore[newY][newX])
                {
                    gScore[newY][newX] = newG;

                    // Compute new neighbor costs
                    Node neighbor(newX, newY);
                    neighbor.g = newG;
                    neighbor.h = std::abs(newX - goal.x) + std::abs(newY - goal.y); // Manhattan distance
                    neighbor.f = neighbor.g + neighbor.h;

                    // Record parent (for path reconstruction)
                    parent[newY][newX] = current;

                    // Add neighbor to open list for further exploration
                    openList.push(neighbor);
                }
            }
        }
    }

    // No path found
    return {};
}

// -------------------------
// Utility: PrintPath
// -------------------------

void PrintPath(const std::vector<Node>& path)
{
    for (const Node& node : path)
    {
        std::cout << "(" << node.x << ", " << node.y << ") ";
        std::cout << "\n";
    }
    std::cout << std::endl;
}
