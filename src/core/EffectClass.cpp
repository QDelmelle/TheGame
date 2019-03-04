
#include "EffectClass.h"
using namespace effect;
	/*burns a "Body target"
		reduce health gradually for an "amount" amount in "duration" seconds
	*/
	void EffectClass:: burn(Body * target, float start, float duration, int amount) {
		float time = ofGetElapsedTimef() - start;
		target->health -= 1 / ofGetFrameRate() / time * amount;
	}
