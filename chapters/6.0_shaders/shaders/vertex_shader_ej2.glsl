#version 330 core
layout (location = 0) in vec3 aPos;

uniform vec4 pos_offset; // we set this variable in the OpenGL code.

void main()
{
	gl_Position = vec4(pos_offset.x + aPos.x, aPos.y, aPos.z, 1.0);
}
