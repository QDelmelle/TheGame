#include "..\core\Character.h"

class Knight : public Character 
{
public:
	Knight(int, int, int, DataManager*, string);
	~Knight();

	ofTexture slashtexture;

	//override
	void getHitBy(Projectile * p);
	void loadData(DataManager *);
};