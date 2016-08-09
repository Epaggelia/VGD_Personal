function hitTestPoint(px, py, r)
{
	var hit = false;

	if (px > r.left() && px < r.right() && py > r.top() && py < r.bottom())
	{
		hit = true;

	}
	return hit;
}

function hitTestRectangle(r1, r2) {
	var hit = false;

	var dx = r1.center().x - r2.center().x;
	var dy = r1.center().y - r2.center().y;

	var sumHalfWidths = r1.halfWidth() + r2.halfWidth();

	if (Math.abs(dx) < sumHalfWidths)
	{
		var sumHalfHeights = r1.halfHeight() + r2.halfHeight();

		if (Math.abs(dy) < sumHalfHeights)
		{
			hit = true;
		}
	}
	return hit;
}

function hitTestCircle(c1, c2)
{
	var hit = false;

	var dx = c1.center().x - c2.center().x;
	var dy = c1.center().y - c2.center().y;

	var magnitude = Math.sqrt(dx * dx + dy * dy);
	var sumRadii = c1.halfWidth() + c2.halfWidth();

	hit = magnitude < sumRadii;

	return hit;
}

function blockRectangle(r1, r2, bounce)
{
	if (bounce === "undefined")
	{
		bounce = false;
	}

	var collisionSide = "";

	var dx = r1.center().x - r2.center().x;
	var dy = r1.center().y - r2.center().y;

	var sumHalfWidths = r1.halfWidth() + r2.halfWidth();

	if (Math.abs(dx) < sumHalfWidths)
	{
		var sumHalfHeights = r1.halfHeight() + r2.halfHeight();

		if (Math.abs(dy) < sumHalfHeights)
		{
			var ox = sumHalfWidths - Math.abs(dx);
			var oy = sumHalfHeights - Math.abs(dy);

			if (ox > oy)
			{
				if (dy > 0)
				{
					collisionSide = "top";
					r1.y += oy;
				} else
				{
					collisionSide = "bottom";
					r1.y -= oy;
				}

				if (bounce)
				{
					r1.xy *= -1;
				}
			} else
			{
				if (dx > 0)
				{
					collisionSide = "left";
					r1.x += ox;
				} else
				{
					collisionSide = "right";
					r1.x -= ox;
				}

				if (bounce)
				{
					r1.xy *= -1;
				}
			}
		} else
		{
			collisionSide = "none";
		}
	} else
	{
		collisionSide = "none";
	}

	return collisionSide;
}

function blockCircle(c1, c2, bounce)
{
	if (bounce === "undefined")
	{
		bounce = false;
	}

	var dx = c1.center().x - c2.center().x;
	var dy = c1.center().y - c2.center().y;

	var magnitude = Math.sqrt(dx * dx + dy * dy);
	var sumRadii = c1.halfWidth() + c2.halfWidth();

	if (magnitude < sumRadii)
	{
		var overlap = sumRadii - magnitude;

		var dirX = dx / magnitude;
		var dirY = dy / magnitude;

		c1.x += overlap * dirX;
		c1.y += overlap * dirY;
	}

	if (bounce)
	{
		var s = {};

		s.x = dy;
		s.y = -dx;

		bounceOffSurface(c1, s);
	}
}

function bounceOffSurface(c, s)
{
	//find the surface vector's left normal
	s.lx = s.y;
	s.ly = -s.x;

	//find the surface magnitude
	s.magnitude = Math.sqrt(s.x * s.x + s.y * s.y);

	//normalize the surface vector
	s.nx = s.x / s.magnitude;
	s.ny = s.y / s.magnitude;

	//DOT  product of incoming velocity and surface
	var dp1 = c.vx * s.nx + c.vy * s.ny;
	//DOT product of incoming velocity and left normal
	var dp2 = c.vx * (s.lx / s.magnitude) + c.vy * (s.ly / s.magnitude);

	//Project incoming velocity onto surface
	var p1X = dp1 * s.nx;
	var p1Y = dp1 * s.ny;

	//Project incoming velocity onto left normal
	var p2X = dp2 * (s.lx / s.magnitude);
	var p2Y = dp2 * (s.ly / s.magnitude);

	//invert the prjection on left normal
	p2X *= -1;
	p2Y *= -1;

	//create the outgoing velocity
	var bounceVX = p1X + p2X;
	var bounceVY = p1Y + p2Y;

	//update the circles velocity
	c.vx = bounceVX;
	c.vY = bounceVY;
}