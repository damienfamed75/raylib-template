#include <raylib.h>

int main(void) {
	InitWindow(800, 450, "Hello");

	Camera camera = {0};
	camera.position = (Vector3){3.0, 3.0, 3.0};
	camera.target = (Vector3){0.0, 1.5, 0.0};
	camera.up = (Vector3){0.0, 1.0, 0.0};
	camera.fovy = 45.0;

	SetTargetFPS(60);
	SetCameraMode(camera, CAMERA_ORBITAL);

	Model dwarf = LoadModel("resources/dwarf.obj");
	Texture2D tex = LoadTexture("resources/dwarf_diffuse.png");

	dwarf.materials[0].maps[MAP_DIFFUSE].texture = tex;

	Vector3 position = {0.0, 0.0, 0.0};

	while (!WindowShouldClose()) {
		UpdateCamera(&camera);
		BeginDrawing();

		ClearBackground(WHITE);

		BeginMode3D(camera);
		DrawModel(dwarf, position, 2.0, WHITE);
		DrawGrid(10, 1.0);
		DrawGizmo(position);

		EndMode3D();

		EndDrawing();
	}

	UnloadTexture(tex);
	UnloadModel(dwarf);

	CloseWindow();

	return 0;
}