Some simple tests to demonstrate performance differences based on cache accesses

	CacheTest1 - Accessing a large 1D array linearly
	CacheTest2 - Accessing a large 1D array in a random order
	MatrixTest1 - Multiplying two matrices with a straightforward implementation
	MatrixTest2 - Multiplying two matrices but transposing one to avoid inefficient access row by row
	MatrixTest3 - Multiplying two matrices using a blocking technique to improve performance