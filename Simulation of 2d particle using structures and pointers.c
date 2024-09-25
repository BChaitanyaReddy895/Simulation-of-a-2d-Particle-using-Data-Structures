#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Particle 
{
 	float x, y; // Position
 	float vx, vy; // Velocity
};
void updateParticle(struct Particle *particle) 
{
 	particle->x += particle->vx; 
 	particle->y += particle->vy;
}
void printParticle(struct Particle *particle) 
{
 	printf("Position: (%.2f, %.2f)\n", particle->x, particle->y);
 	printf("Velocity: (%.2f, %.2f)\n\n", particle->vx, particle->vy);
}
int main() 
{
 // Seed the random number generator
 	srand(time(NULL));
 	struct Particle particles[4];
 // Generate random particles
	int i;
 	for (i = 0; i < 3; i++) 
	{
 		particles[i].x = (float)(rand() % 100) / 10.0; // Random position between 0 and 10
 		particles[i].y = (float)(rand() % 100) / 10.0; // Random position between 0 and 10
 		particles[i].vx = (float)(rand() % 21 - 10) / 10.0; // Random velocity between -1 and 1
 		particles[i].vy = (float)(rand() % 21 - 10) / 10.0; // Random velocity between -1 and 1
 	}
 	for (i = 0; i < 3; i++) 
	{
 		printf("Particle %d:\n", i + 1);
 		printParticle(&particles[i]);
 		int step;
 		for (step = 1; step <= 5; step++) 
		{
 			updateParticle(&particles[i]);
 			printf("After Step %d:\n", step);
 			printParticle(&particles[i]);
 		}
 	}
 	return 0;
} 

