#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

static GLfloat g_vertex_arr[] = { -1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f,
		1.0f, 0.0f };

static void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action,
		int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

static GLFWwindow *g_window;
static void init_glfw(){
	glfwSetErrorCallback(error_callback);

	if (GL_FALSE == glfwInit()) {
		exit(EXIT_FAILURE);
	}

	g_window = glfwCreateWindow(640, 480, "OpenGL", NULL, NULL);
	if (!g_window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(g_window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(g_window, key_callback);
}

static void init_glew(){
	GLenum glew_err;

	glewExperimental = GL_TRUE;
	glew_err = glewInit();
	if (GLEW_OK != glew_err) {
		printf("%s\n", glewGetErrorString(glew_err));
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
}

int main(int argc, char **argv) {
	GLuint vb;

	init_glfw();
	init_glew();



	glGenBuffers(1, &vb);
	glBindBuffer(GL_ARRAY_BUFFER, vb);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_arr), g_vertex_arr,
			GL_STATIC_DRAW);

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	while (!glfwWindowShouldClose(g_window)) {
//		float ratio;
		int width, height;
//
		glfwGetFramebufferSize(g_window, &width, &height);
//		ratio = width / (float) height;
//
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
//
//		glMatrixMode(GL_PROJECTION);
//		glLoadIdentity();
//		glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
//
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

//		glBegin(GL_TRIANGLES);
//		glColor3f(1.f, 0.f, 0.f);
//		glVertex3f(-0.6f, -0.4f, 0.f);
//		glColor3f(0.f, 1.f, 0.f);
//		glVertex3f(0.6f, -0.4f, 0.f);
//		glColor3f(0.f, 0.f, 1.f);
//		glVertex3f(0.f, 0.6f, 0.f);
//		glEnd();

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_VERTEX_ARRAY, vb);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glDisableVertexAttribArray(0);

		glfwSwapBuffers(g_window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
