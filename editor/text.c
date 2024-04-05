#include "raylib.h"

#define TEXTMAX 10

int main(void){
	int width = 850;
	int height = 400;
	int frameCounter = 0;
	int frameSinceSave = 0;
	
	int pressed = 0;
	char text[TEXTMAX];
	int textIndex = 0;
	
	Rectangle screen = {0, 0, width, height};
	bool shouldSave = false;
	
	InitWindow(width, height, "Raylib Text Editor");
	
	SetTargetFPS(60);
	
	while(!WindowShouldClose()){
		if(frameCounter == 120){
			frameCounter = 0;
		}
		
		if(CheckCollisionPointRec(GetMousePosition(), screen)){
			SetMouseCursor(MOUSE_CURSOR_IBEAM);
		}
		else{
			SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		}
		
		while(pressed = GetCharPressed()){
			if(textIndex != TEXTMAX - 1){
				text[textIndex] = (char)pressed;
				text[++textIndex] = '\0';
			}
		}
		
		if(IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_S)){
			shouldSave = true;
			frameSinceSave = 0;
		}
		
		if(IsKeyPressed(KEY_BACKSPACE)){
			textIndex--;
			if(textIndex < 0){
				textIndex = 0;
			}
			text[textIndex] = '\0';
		}
		
		BeginDrawing();
	
		ClearBackground(WHITE);
		
		DrawText(text, 0, 0, 20, BLACK);
		
		if(shouldSave){
			if(frameSinceSave < 120){
				DrawText("Saved", 780, 50, 20, BLACK);
			}
		}
		
		DrawFPS(780, 0);
		
		EndDrawing();
		
		++frameCounter;
		++frameSinceSave;
	}
	
	CloseWindow();
	
	return 0;
}