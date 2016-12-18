#include "region_grower.h"

void RegionGrower::setImage(const char * filename)
{
	Input.ReadFromFile(filename);
	//reads in the file
}

void RegionGrower::setSeed(int x, int y)
{
	sprout.x = x;
	sprout.y = y;
	//Sets the initial point to fill from
}

void RegionGrower::setReplacement(int red, int green, int blue)
{
	NewRed = red;
	NewGreen = green;
	NewBlue = blue;
	//sets the new RGB color value
}

void RegionGrower::update()
{
	int h = Input.TellHeight();
	int w = Input.TellWidth();
	//sets the height and the width values
	
	LinkedStack<seed> position;
	position.push(sprout);
	seed pos = position.top();
	//pushes the seed to the stack
	
	Start = Input.GetPixel(pos.x, pos.y);
	int startRed = Start.Red;
	int startGreen = Start.Green;
	int startBlue = Start.Blue;
	//checks the color values for the seed point

	NewCol.Red = NewRed;
	NewCol.Green = NewGreen;
	NewCol.Blue = NewBlue;


	int stackCt = 1;
	while (!position.isempty())
	{
		pos = position.top();
		Input.SetPixel(pos.x, pos.y, NewCol);
		position.pop();
		//changes the color value for the top pixel to the new color

		stackCt--;
		//the count of the stack used for debugging

		int up = pos.y + 1;
		int down = pos.y - 1;
		int left = pos.x - 1;
		int right = pos.x + 1;
		//sets values for the position modifiers

		if (left >= 0 && left < w)
		{
			//checks if left is within the image
			if (Input(left, pos.y)->Red == startRed && Input(left, pos.y)->Green == startGreen && Input(left, pos.y)->Blue == startBlue)
			{
				sprout.x = left;
				sprout.y = pos.y;
				position.push(sprout);
				stackCt++;
				//pushes the modified value of sprout into the stack
			}
		}
		if (right >= 0 && right < w)
		{
			//checks if right is within the image
			if (Input(right, pos.y)->Red == startRed && Input(right, pos.y)->Green == startGreen && Input(right, pos.y)->Blue == startBlue)
			{
				sprout.x = right;
				sprout.y = pos.y;
				position.push(sprout);
				stackCt++;
				//pushes the modified value of sprout into the stack
			}
		}
		if (up > 0 && up < h)
		{
			//checks if up is within the image
			if (Input(pos.x, up)->Red == startRed && Input(pos.x, up)->Green == startGreen && Input(pos.x, up)->Blue == startBlue)
			{
				sprout.x = pos.x;
				sprout.y = up;
				position.push(sprout);
				stackCt++;
				//pushes the modified value of sprout into the stack
			}
		}
		if (down >= 0 && down < h)
		{
			//checks if down is within the image
			if (Input(pos.x, down)->Red == startRed && Input(pos.x, down)->Green == startGreen && Input(pos.x, down)->Blue == startBlue)
			{
				sprout.x = pos.x;
				sprout.y = down;
				position.push(sprout);
				stackCt++;
				//pushes the modified value of sprout into the stack
			}
		}
	}
}

void RegionGrower::getOutput(const char * filename)
{
	Input.WriteToFile(filename);
	// outputs the BMP to a file
}