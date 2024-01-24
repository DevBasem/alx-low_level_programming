#!/usr/bin/python3
"""
5-island_perimeter
"""


def island_perimeter(grid):
    """
    Calculates the perimeter of the island described in grid.
    Args:
        - grid (list of list of integers): 2D grid representing the island.

    Returns:
        - int: Perimeter of the island.
    """

    perimeter = 0

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                perimeter += 4

                # Check if there's a land cell to the left
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

                # Check if there's a land cell above
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2

    return perimeter
