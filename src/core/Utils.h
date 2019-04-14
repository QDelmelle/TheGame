#pragma once



class Utils {
public:
	enum Effect {
		PHYSICAL,
		MAGIC,
		POISON,
		BURN,
		SLOW,
		STUN,
		ONESHOT,
		BLEED,
		HEAL,
		SPEEDUP,
		REVIVE,
		INVINCIBLE,
		INVISIBLE,
	};
	enum Status {
		ALIVE,
		DYING,
		DEAD,
	};
};
