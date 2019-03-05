
#include "EffectClass.h"

	/*burns a "Body target"
		reduce health gradually for an "amount" amount in "duration" seconds
	*/
	void EffectClass:: burn(Body * target, float start, float duration, int amount) {
		float time = ofGetElapsedTimef() - start;
		if(time<duration){
			target->health -= 1 / ofGetFrameRate() / time * amount;
			cout << target->health << endl;
		}
	}
