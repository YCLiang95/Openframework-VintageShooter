#include "Pawn.h"



Pawn::Pawn()
{
}


Pawn::~Pawn()
{
}

void Pawn::draw() {
	ofPushMatrix();
	//Transform based on parent position
	ofTranslate(transform.getPosition());
	//transform based on parent rotation
	ofRotate(transform.getAngle() * 180 / PI);
		ofPushMatrix();
			//The center of the sprite will be used by default
			ofTranslate(-sprite.image.getWidth() / 2, -sprite.image.getHeight() / 2);
			sprite.image.draw(0, 0);
		ofPopMatrix();
	ofPopMatrix();
}
