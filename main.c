#include <assert.h>
#include <errno.h>
#include <math.h>
#include <raylib.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define INIT_WIDTH 1280
#define INIT_HEIGHT 720
#define FPS 60
#define BG_COLOR BEIGE
#define FG_COLOR BLACK

int main(void) {
  InitWindow(INIT_WIDTH, INIT_HEIGHT, "Metaballs");
  // SetTargetFPS(FPS);

  Image imBlank = GenImageColor(INIT_WIDTH, INIT_HEIGHT, BLANK);
  Texture2D texture = LoadTextureFromImage(imBlank);
  UnloadImage(imBlank);

  Shader shader = LoadShader(NULL, "./shader.fs");
  int ball2Loc = GetShaderLocation(shader, "ball2");
  Vector2 ball2 = GetMousePosition();
  SetShaderValue(shader, ball2Loc, &ball2, SHADER_UNIFORM_VEC2);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BG_COLOR);

    ball2 = GetMousePosition();
    SetShaderValue(shader, ball2Loc, &ball2, SHADER_UNIFORM_VEC2);

    BeginShaderMode(shader);
    DrawTexture(texture, 0, 0, BG_COLOR);
    EndShaderMode();

    DrawFPS(10, 10);

    EndDrawing();
  }

  return EXIT_SUCCESS;
}
