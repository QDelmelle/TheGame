#pragma once

#include "Body.h"

enum effect {
	PHYSICAL = 1,
	MAGIC = 2,
	POISON = 3,
	BURN = 4,
	SLOW = 5,
	STUN = 6,
	ONESHOT = 7,
	BLEED = 8,
	HEAL = 9,
	SPEEDUP = 10,
	REVIVE = 11,
	INVINCIBLE = 12,
	INVISIBLE = 13,
};

class EffectClass {
public:
	static void	burn(Body * target, float start, float duration, int amount);
};