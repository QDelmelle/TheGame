

// shape: any drawable moving or static object must implement this.
class Shape
{
public:
	Shape(int, int, int);
	~Shape();

	int x, y, size;		// position of the center and default size of the object.
	int currentSize; // actual size of the object at the moment.
	void update(); // update size, position, etc to make it evolve.
	void draw(); // draw function, called on each frame.
};
