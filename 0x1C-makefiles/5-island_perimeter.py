#!/usr/bin/python3
"""Defines an island perimeter measuring function."""

def island_perimeter(grid):
    """returns the parameter of the island

    Args:
        grid (list): list of list that represent the island
    
    Returns: 
        the parameter of the island
    """

    row = len(grid)
    column = len(grid[0])
    parameter = 0

    for i in range(row):
        for j in range(column):
            if grid[i][j] == 1:
                parameter += 4
                if j > 0 and grid[i][j - 1] == 1:
                    parameter -= 1
                if j < len(grid[0]) - 1 and grid[i][j + 1] == 1:
                    parameter -= 1
                if i > 0 and grid[i - 1][j] == 1:
                    parameter -= 1
                if i < len(grid) - 1 and grid[i + 1][j] == 1:
                    parameter -= 1
        
    return parameter
