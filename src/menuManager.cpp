#include "menuManager.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#define MAX_INPUT_CHARS     9

char name[MAX_INPUT_CHARS + 1];      // NOTE: One extra space required for null terminator char '\0'
int letterCount = 0;

menuManager::menuManager()
{
}

menuManager::~menuManager() noexcept
{
	UnloadTexture(Background);
}

void menuManager::titleScreen()
{
	DrawText("CLICK ENTER TO START", 230, 300, 30, WHITE);
}

void menuManager::loadingAssets()
{
	DrawText("BASIC ASSETS LOADING", 230, 300, 30, BLACK);
}

void menuManager::MenuScreen()
{

	DrawText("FLAPPY CIRCLE", 240, 100, 40, BLACK);
	DrawText("PRESS E TO PLAY", 295, 300, 20, BLACK);
	
}

void menuManager::replayGame()
{
	DrawText("Want to play again?", 260, 300, 30, BLACK);
	DrawText("Click Y if Yes or Escape to Exit Windows", 130, 360, 30, BLACK);
}



std::string menuManager::insertscore()
{
    Rectangle textBox = { GetScreenWidth() / 2.0f - 100, 180, 225, 50 };
    bool mouseOnText = false;

    int framesCounter = 0;

    if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
    else mouseOnText = false;

    if (mouseOnText)
    {
        // Set the window's cursor to the I-Beam
        SetMouseCursor(MOUSE_CURSOR_IBEAM);

        // Get char pressed (unicode character) on the queue
        int key = GetCharPressed();

        // Check if more characters have been pressed on the same frame
        while (key > 0)
        {
            // NOTE: Only allow keys in range [32..125]
            if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
            {
                name[letterCount] = (char)key;
                name[letterCount + 1] = '\0'; // Add null terminator at the end of the string.
                letterCount++;
            }

            key = GetCharPressed();  // Check next character in the queue
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            letterCount--;
            if (letterCount < 0) letterCount = 0;
            name[letterCount] = '\0';
        }
    }
    else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

    if (mouseOnText) framesCounter++;
    else framesCounter = 0;



    DrawRectangleRec(textBox, LIGHTGRAY);
    if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, WHITE);
    else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, WHITE);

    DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, BLACK);


    if (mouseOnText)
    {
        if (letterCount < MAX_INPUT_CHARS)
        {
            // Draw blinking underscore char
            if (((framesCounter / 20) % 2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, GRAY);
        }
        else DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
    }
	

    return name;
}



void menuManager::setTexture(Texture2D background_in)
{
	  Background = background_in;
}

Texture2D menuManager::getTexture()
{
	return Background;
}





