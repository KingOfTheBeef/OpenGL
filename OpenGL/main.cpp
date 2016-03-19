
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include <SDL2\SDL.h>
#include <gl\glew.h>
#include <SDL2\SDL_opengl.h>
#include <gl\GLU.h>

const int width = 400;
const int height = 400;

GLuint generateProgram(const char * frag_shader_path, const char * vert_shader_path);

string read_file(const char *address);

int main(int argc, char **argv)
{

	//glewExperimental = TRUE;
	//cout <<  << endl;
	//cout << glewGetErrorString(glewInit()) << endl;
	SDL_Window* window = NULL;
	//SDL_Surface* screen = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Error intialising screen with an error of " << SDL_GetError();
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	window = SDL_CreateWindow("OpenGL attempt", 100, 100, width, height, SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL);
	if (!window)
	{
		cout << SDL_GetError();
	}
	cout << SDL_GetError();
	SDL_GLContext context = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, context);
	cout << SDL_GetError();
	SDL_GL_SetSwapInterval(1);
	cout << "Just want to print something"<< endl;
	cout << SDL_GetError();
	//glewInit();
	//cout << glewGetErrorString(glewInit()) << endl;
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	
	if (err != GLEW_OK)
	{
		cout << "GlewInit error";
		exit(1);
	}

	//glPointSize(50.0);
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};
	GLuint VertexBuffer;
	glGenBuffers(1, &VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	glClearColor(1.0f, 0.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GLuint prog = generateProgram("Shaders1.frag", "Shaders1.vert");
	glUseProgram(prog);
	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
	glVertexAttribPointer( 0, 3, GL_FLOAT,GL_FALSE, 0,(void*)0);

	 // Draw the triangle !
		 glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
		 glDisableVertexAttribArray(0);
		 SDL_GL_SwapWindow(window);
		 SDL_Delay(100000);
	







	/* Delete our opengl context, destroy our window, and shutdown SDL */

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}



GLuint generateProgram(const char * frag_shader_path, const char * vert_shader_path)
{
	cout << "Starting" << endl;
	GLuint vert_ID = glCreateShader(GL_VERTEX_SHADER);
	GLuint frag_ID = glCreateShader(GL_FRAGMENT_SHADER);

	string vert_shader_code = read_file(vert_shader_path);

	string frag_shader_code = read_file(frag_shader_path);
	char const * VertexSourcePointer = vert_shader_code.c_str();
 	glShaderSource(vert_ID, 1, &VertexSourcePointer, NULL);
 	glCompileShader(vert_ID);
	GLint Result = GL_FALSE;
	int InfoLogLength;

	glGetShaderiv(vert_ID, GL_COMPILE_STATUS, &Result);
 	glGetShaderiv(vert_ID, GL_INFO_LOG_LENGTH, &InfoLogLength);
 	if (InfoLogLength > 0) {
			string VertexShaderErrorMessage;
			glGetShaderInfoLog(vert_ID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
			cout << VertexShaderErrorMessage[0] << endl;
	
	}
	else
	{
		cout << "All fine" << endl;
	}

	char const * FragmentSourcePointer = frag_shader_code.c_str();
	glShaderSource(frag_ID, 1, &FragmentSourcePointer, NULL);
	glCompileShader(frag_ID);

	Result = GL_FALSE;
	InfoLogLength = 0;

	glGetShaderiv(frag_ID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(frag_ID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	
	if (InfoLogLength > 0) {
		//string FragmentShaderErrorMessage;
		vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(frag_ID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		for (char n : FragmentShaderErrorMessage)
		{
			cout << n << "";
		}
		//cout << FragmentShaderErrorMessage << endl;

	}
	else
	{
		cout << "All fine" << endl;
	}

	GLuint program = glCreateProgram();
	glAttachShader(program, vert_ID);
	glAttachShader(program, frag_ID);
	glLinkProgram(program);



	glGetProgramiv(program, GL_LINK_STATUS, &Result);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		vector<char> ProgramErrorMessage(InfoLogLength+1);
		glGetProgramInfoLog(program, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		cout << &ProgramErrorMessage[0] << endl;
	}
	else
	{
		cout << "All fine" << endl;
	}



	glDetachShader(program, vert_ID);
	glDetachShader(program, frag_ID);

	glDeleteShader(vert_ID);
	glDeleteShader(frag_ID);

	return program;



}

string read_file(const char *address)
{
	ifstream file;
	file.open(address);
	string shader_code;
	if (file.is_open())
	{
		cout << "Is open" << endl;
		string line = "";
		while (getline(file, line))
			shader_code += line + " \n";

		//vert_shader >> vert_shader_code;

	}
	else
	{
		cout << "Error" << endl;
	}
	cout << shader_code;
	file.close();
	return shader_code;
}