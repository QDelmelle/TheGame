#pragma once
class Etoile
{
public:
	Etoile(int,int, int);
	~Etoile();

	int x, y;
	void set(int, int, int);
	void draw();
	float size;
};

