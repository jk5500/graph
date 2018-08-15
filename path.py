
grid = [[0, 0, 0, 0, 0, 1],
        [1, 1, 0, 0, 0, 1],
        [0, 0, 0, 1, 0, 0],
        [0, 1, 1, 0, 0, 1],
        [0, 1, 0, 0, 1, 0],
        [0, 1, 0, 0, 0, 2]]



def find_path(x,y):
	if grid[x][y] == 2:
		print('found destination')
		return True
	if grid[x][y] == 1:
		print('found wall at ({}, {})'.format(x, y))
		return False

	if grid[x][y] == 3:
		return False


	print('visited at ({}, {})'.format(x, y))
	grid[x][y] = 3


	if ((x < len(grid) -1 and find_path(x+1, y)) or (y < len(grid) -1 and find_path(x, y+1)) \
		or (x > 0 and find_path(x-1, y)) or (y > 0 and find_path(x, y-1))):
		return True

	return False

print(find_path(0, 0))

