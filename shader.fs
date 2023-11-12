#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

out vec4 finalColor;

const vec2 ball1 = vec2(300, 250);
uniform vec2 ball2;
const vec4 color = vec4(1, 1, 1, 1);

void main() {
      vec2 coord = fragTexCoord;
			coord.x *= 1280;
			coord.y *= 720;

      // float s = (1.0f / sqrtf((coord - ball1, 2) + powf(y1 - ball1_y, 2)) +
      //            1.0f / sqrtf(powf(x1 - ball2_x, 2) + powf(y1 - ball2_y, 2)));

			float s = 1.0f/distance(coord, ball1) + 1.0f/distance(coord, ball2);
			finalColor = fragColor;

      if (s >= 0.01f) {
				finalColor = vec4(0, 0, 0, 1);
      }
}
