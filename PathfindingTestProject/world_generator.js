// fill the world with walls
function createWorld(wallType)
{
	console.log('Creating world...');

	// create emptiness
	for (var x = 0; x < worldWidth; x++)
	{
		world[x] = [];

		for (var y = 0; y < worldHeight; y++)
		{
			world[x][y] = 0;
		}
	}

	switch (wallType){
		case "bolder":
			for (var x = 0; x < worldWidth; x++)
			{
				for (var y = 0; y < worldHeight; y++)
				{
					if (x>5 && x <10)
						if (y>5 && y<10)
						world[x][y] = 1;
					
				}
			}
			break;
		case "level_one":
			for (var x = 0; x < worldWidth; x++)
			{
				for (var y = 0; y < worldHeight; y++)
				{
					//borderwalls
					if (x==0)
						if (y>0 && y<=worldHeight)
							world[x][y] = 1;
					
					if (x==15)
						if (y>=0 && y<=worldHeight)
							world[x][y] = 1;
					
					if (x>=0 && x <=worldWidth)
						if (y==0)
							world[x][y] = 1;
					
					if (x>=0 && x <=worldWidth)
						if (y==worldHeight)
							world[x][y] = 1;
					//
					
					if (x==10)
						if (y>=0 && y <= worldHeight/2)
							world[x][y] = 1;
					
					if (x>=10 && x <=13)
						if (y==worldHeight/2)
							world[x][y] = 1;
					
					if (x>=3 && x <=7)
						if (y>=4 && y<=6)
							world[x][y] = 1;
					
				}
			}
			break;
		default :
		// scatter some walls
			for (var x = 0; x < worldWidth; x++)
			{
				for (var y = 0; y < worldHeight; y++)
				{
					if (Math.random() > 0.75)
						world[x][y] = 1;
				}
			}
			break;
	}

	// calculate initial possible path
	// note: unlikely but possible to never find one...
	currentPath = [];
	while (currentPath.length == 0) //well current path is empty
	{
		//make random path start point
		pathStart = [Math.floor(Math.random() * worldWidth), Math.floor(Math.random() * worldHeight)];
		//make random path end point
		pathEnd = [Math.floor(Math.random() * worldWidth), Math.floor(Math.random() * worldHeight)];
		
		if (world[pathStart[0]][pathStart[1]] == 0) // checks if starting point is in a valid place (AKA not in a rock)
			currentPath = findPath(world, pathStart, pathEnd,true); // assigns random start and end to current path if it counts as valid
		else
			console.log("Starting point not valid...");
	}
	redraw();
}