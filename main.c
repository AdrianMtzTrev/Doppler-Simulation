#include<stdio.h>
#include<stdlib.h>
#include<raylib.h>

#define WIDTH 1920
#define HEIGHT 1080
#define MAX_WAVES 60
#define OBJECT_SPEED 50.0f
#define WAVE_SPEED 60
#define WAVE_FREQ 0.3f

Color objectColor = (Color){255, 255, 255, 255};
Color waveColor = (Color){255, 255, 255, 255};

struct Object{
	float x, y;
};

struct DopplerWave{
	float x,y,r;
	bool active;
};

struct Object object = (struct Object){WIDTH/2, HEIGHT/2};
struct DopplerWave waves[MAX_WAVES];
unsigned int current_waves = 0;
float time_last_wave = 0.0f;


void draw_object(){
	DrawCircle(object.x, object.y, 20, objectColor);
}

void draw_waves(){
	for(int i=0; i<MAX_WAVES; i++){
		if(waves[i].active)
			DrawCircleLines(waves[i].x, waves[i].y, waves[i].r, waveColor);
	}
}

void emit_wave(float delta){
	if (current_waves >= MAX_WAVES)
		current_waves = 0;
	if (time_last_wave > WAVE_FREQ){
		waves[current_waves] =  (struct DopplerWave){object.x, object.y, 1, true};
		current_waves++;
		time_last_wave = 0;
	}else{
		time_last_wave += delta;
	}
}

void draw(){
	draw_object();
	draw_waves();
}

void move_object(float delta){
	if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) object.x += (OBJECT_SPEED * delta);
	if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) object.x -= (OBJECT_SPEED * delta);
	if(IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) object.y -= (OBJECT_SPEED * delta);
	if(IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) object.y += (OBJECT_SPEED * delta);
}

void move_waves(float delta){
	for(int i = 0; i < MAX_WAVES; i++){
		if(waves[i].active)
			waves[i].r += (WAVE_SPEED * delta);
	}
}

void update(){
	float delta_time = GetFrameTime();
	emit_wave(delta_time);
	move_object(delta_time);
	move_waves(delta_time);
}


int main(void)
{
	InitWindow(WIDTH, HEIGHT, "Raylib - Doppler Effect");
	SetTargetFPS(30);
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(BLACK);
		update();
		draw();
		DrawFPS(10,10);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
