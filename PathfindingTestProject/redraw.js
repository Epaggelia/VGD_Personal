function drawLand() {
	for (var x = 0; x < worldWidth; x++) // loop through tiles left to right
	{
		for (var y = 0; y < worldHeight; y++) // loop through tiles top to bottom
		{

			// choose a sprite to draw
			// choice based on results of Math.random in createWorld function - (25% chance of being a rock)
			switch (world[x][y])
			{
				case 1:
					spriteNum = 1;
					break;
				default:
					spriteNum = 0;
					break;
			}

			// draw it
			//ctx.drawImage(img,sx,sy,swidth,sheight,x,y,width,height);
			ctx.drawImage(spritesheet,
					spriteNum * 32, 0,
					32, 32,
					x * tileWidth, y * tileHeight,
					tileWidth, tileHeight);
		}
	}
}

function drawPath() {
	for (rp = 0; rp < currentPath.length; rp++)
	{
		switch (rp)
		{
			case 0: // first array place
				spriteNum = 2; // start
				break;
			case currentPath.length - 1: //last array place
				spriteNum = 3; // end
				break;
			default: // everything else
				spriteNum = 4; // path node
				break;
		}

		ctx.drawImage(spritesheet,
				spriteNum * 32, 0,
				32, 32,
				currentPath[rp][0] * tileWidth,
				currentPath[rp][1] * tileHeight,
				tileWidth, tileHeight);
	}
}

