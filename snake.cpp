#include "main.h"

class Snake
{
private:
	enum direction
	{
		left, right, up, down, stay
	};
	direction Pdirection;
	std::vector<coord> body;
	bool growth;
public:

	Snake(int x = 0, int y = 0) : growth(false), Pdirection(stay)
	{
		body.push_back({ x,y });
	}

	/*
	* Move body parts from end to beginning(except head and duplicated last one if growth = true)
	* by setting position of one part with position of newer one.
	* Head's move depence on direction.
	*/
	void moveBody()
	{
		int i = 0;
		if (growth)
		{
			growth = false;
			i--;
			body.push_back(body[body.size() - 1]);
		}
		

		for (i += body.size() - 1; i > 0; i--)
		{
			body[i] = body[i - 1];
		}

		if (Pdirection == up)
			body[0].x--;
		else if (Pdirection == down)
			body[0].x++;
		else if (Pdirection == left)
			body[0].y -= 2;
		else if (Pdirection == right)
			body[0].y += 2;

	}
	const coord& getLast() { return body[body.size() - 1]; }
	const coord& getFirstIndex() { return body.size() > 1 ? body[1] : coord(-1, -1); }
	const coord& getHead() { return body[0]; }

	void addPart()
	{
		growth = true;
	}
	void handleInput()
	{
		direction previous = Pdirection;

		do
		{
			if (GetAsyncKeyState(0x57))
				Pdirection = up;
			if (GetAsyncKeyState(0x41))
				Pdirection = left;
			if (GetAsyncKeyState(0x44))
				Pdirection = right;
			if (GetAsyncKeyState(0x53))
				Pdirection = down;
		}
		while (Pdirection == stay);


		//check if head won't try to hit body[1]
		if (body.size() > 1 && 
			   (Pdirection == up && body[0].x-1 == body[1].x || 
				Pdirection == down && body[0].x+1 == body[1].x ||
				Pdirection == left && body[0].y-2 == body[1].y ||
				Pdirection == right && body[0].y+2 == body[1].y))
			Pdirection = previous;
	}

	void clear(int x = 1, int y = 2)
	{
		body.clear();
		body.push_back({ x,y });
		Pdirection = stay;
	}
};
