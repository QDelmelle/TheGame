#pragma once



class Utils {
public:
	enum effect {
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
	enum status {
		ALIVE,
		DYING,
		DEAD,
	};
};
