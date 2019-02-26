#include "Pawn.h"



Pawn::Pawn()
{
}


Pawn::~Pawn()
{
}

void Pawn::draw() {
	ofPushMatrix();
	ofTranslate(transform.getPosition());
	ofRotate(transform.angle * 180 / PI);
		ofPushMatrix();
			ofTranslate(-sprite.image.getWidth() / 2, -sprite.image.getHeight() / 2);
			sprite.image.draw(0, 0);
		ofPopMatrix();
	ofPopMatrix();
}
