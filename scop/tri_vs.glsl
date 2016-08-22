#version 400
layout(location = 0) in vec3 vertex_pos;
layout(location = 1) in vec3 vertex_normal;
uniform mat4 MVP;
uniform mat4 MV;
out vec4 normal;
out vec4 wpos;
out mat4 mv;
void main () {
	normal = vec4(vertex_normal, 1.0f);
	mv = MV;
	wpos = MVP * vec4(vertex_pos, 1.0);
	gl_Position = wpos;
	//vec4 wpos = MVP * vec4(vertex_pos, 1.0);
	//gl_Position = wpos;
}
