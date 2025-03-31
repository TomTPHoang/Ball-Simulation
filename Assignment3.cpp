#include "raylib.h"
#include <iostream>
#include <cmath>

struct Ball {
    Vector2 position;
    Vector2 velocity;
    float radius;
};

// Globals
Ball ball = { {400, 300}, {200, 150}, 20 }; // Initial position and velocity
float targetFPS = 60;
bool restartFlag = false;

void ResetBall() {
    ball.position = { 400, 300 };
    ball.velocity = { 200, 150 };
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Bouncing Ball Simulation");
    SetTargetFPS(targetFPS);

    float elapsedTime = 0.0f;
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
        if (IsKeyPressed(KEY_R)) restartFlag = true;
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

        elapsedTime += deltaTime;

        // Rendering
        BeginDrawing();
        ClearBackground(DARKGRAY);

        // Draw ball
        DrawCircleV(ball.position, ball.radius, RED);

        // Debug Overlay
        DrawText(TextFormat("FPS: %d", GetFPS()), screenWidth - 150, 10, 20, WHITE);
        DrawText(TextFormat("Elapsed Time: %.2f sec", elapsedTime), screenWidth - 220, 40, 20, WHITE);
        DrawText(TextFormat("Delta Time: %.4f sec", deltaTime), screenWidth - 220, 70, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
