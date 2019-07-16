#include "..\core\Character.h"

class Knight : public Character 
{
public:
	Knight(int, int, int, DataManager*, string);
	~Knight();

	ofTexture slashtexture;

	void slash();

	//override
	void getHitBy(Projectile * p);
	void loadData(DataManager *);
};