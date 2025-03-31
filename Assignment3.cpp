#include "raylib.h"
#include <iostream>
#include <cmath>

// Ball structure 
struct Ball {
    Vector2 position;
    Vector2 velocity;
    float radius;
};

// Globals
Ball ball = { {400, 300}, {0, 0}, 20 };
float targetFPS = 60;
bool restartFlag = false;
float elapsedTime = 0.0f;

// Function to reset ball position and randomize velocity
void ResetBall() {
    ball.position = { 400, 300 }; // Fixed starting position
    ball.velocity = { (float)GetRandomValue(-300, 300), (float)GetRandomValue(-300, 300) }; // Randomize velocity 
    elapsedTime = 0.0f; // Reset the time to 0 on restart
}

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "Bouncing Ball Simulation");

    // Randomize velocity when the program starts
    ResetBall();

    SetTargetFPS(targetFPS);

    double lastTime = GetTime();

    while (!WindowShouldClose()) {
        double currentTime = GetTime();
        float deltaTime = static_cast<float>(currentTime - lastTime);
        lastTime = currentTime;

        // Prevent large delta times (breakpoint handling)
        if (deltaTime > 0.1f) deltaTime = 0.1f;

        // Handle input
        if (IsKeyPressed(KEY_ONE)) SetTargetFPS(60);
        if (IsKeyPressed(KEY_TWO)) SetTargetFPS(120);
        if (IsKeyPressed(KEY_THREE)) SetTargetFPS(0); // Uncapped FPS
        if (IsKeyPressed(KEY_R)) {
            restartFlag = true;
        }
        if (IsKeyPressed(KEY_ESCAPE)) break;

        if (restartFlag) {
            ResetBall();
            restartFlag = false;
        }

        // Ball movement (frame rate independent)
        ball.position.x += ball.velocity.x * deltaTime;
        ball.position.y += ball.velocity.y * deltaTime;

        // Collision detection and response
        if (ball.position.x - ball.radius <= 0 || ball.position.x + ball.radius >= screenWidth) {
            ball.velocity.x *= -1;
        }
        if (ball.position.y - ball.radius <= 0 || ball.position.y + ball.radius >= screenHeight) {
            ball.velocity.y *= -1;
        }

        // Rendering
        BeginDrawing();
        ClearBackground(DARKGRAY);

        // Draw ball
        DrawCircleV(ball.position, ball.radius, RED);

        // Debug Overlay (Right side)
        DrawText(TextFormat("FPS: %d", GetFPS()), screenWidth - 150, 10, 20, WHITE);
        DrawText(TextFormat("Elapsed Time: %.2f sec", elapsedTime), screenWidth - 220, 40, 20, WHITE);
        DrawText(TextFormat("Delta Time: %.4f sec", deltaTime), screenWidth - 220, 70, 20, WHITE);
        DrawText(TextFormat("Frame Time: %.4f sec", GetFrameTime()), screenWidth - 220, 100, 20, WHITE);

        elapsedTime += deltaTime; // Update elapsed time for each frame

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
