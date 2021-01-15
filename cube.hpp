#include <iostream>
#include <vector>
#include <glm/glm.hpp>

#include "cs488-framework/CS488Window.hpp"
#include "cs488-framework/OpenGLImport.hpp"
#include "cs488-framework/ShaderProgram.hpp"

using namespace std;

class Cube {
private:
    GLfloat side_length = 1.0f;
    vector<glm::vec3> vertex_data;//[8]
    vector<unsigned int> indices;//[36] specify indices to draw rectangles
    GLuint cube_vao; // Vertex Array Object
    GLuint cube_vbo; // Vertex Buffer Object
    GLuint cube_ebo; // element Array Object
    
public:
    glm::vec3 center;
    Cube(glm::vec3 position);
    void set_buffer(const ShaderProgram& s);
    void draw();
    void set_ebo();
    
};
