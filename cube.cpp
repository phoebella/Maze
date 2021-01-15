#include <iostream>
#include <vector>
#include "cube.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



using namespace std;


Cube::Cube(glm::vec3 start):center(start){
    GLfloat half_len = side_length*0.5;
    //front face 1st triangle
    vertex_data.push_back(center+glm::vec3( half_len, half_len, half_len )); //top right
    vertex_data.push_back(center+glm::vec3( half_len, -half_len, half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( -half_len, half_len, half_len ));//top left
    //front face 2nd triangle
    vertex_data.push_back(center+glm::vec3( half_len, -half_len, half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( -half_len, -half_len, half_len ));//bottom left
    vertex_data.push_back(center+glm::vec3( -half_len, half_len, half_len ));//top left
    //back face 1st triangle
    vertex_data.push_back(center+glm::vec3( half_len, half_len, -half_len )); //top right
    vertex_data.push_back(center+glm::vec3( half_len, -half_len, -half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( -half_len, half_len,- half_len ));//top left
    //back face 2nd triangle
    vertex_data.push_back(center+glm::vec3( half_len, -half_len, -half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( -half_len, -half_len, -half_len ));//bottom left
    vertex_data.push_back(center+glm::vec3( -half_len, half_len,- half_len ));//top left
    //left face 1st triangle
    vertex_data.push_back(center+glm::vec3( -half_len, half_len, -half_len ));//top right
    vertex_data.push_back(center+glm::vec3( -half_len, -half_len, -half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( -half_len, half_len, half_len ));//top left
    //left face 2nd triangle
    vertex_data.push_back(center+glm::vec3( -half_len, -half_len, -half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( -half_len, -half_len, half_len ));//bottom left
    vertex_data.push_back(center+glm::vec3( -half_len, half_len, half_len ));//top left
    //right face 1st triangle
    vertex_data.push_back(center+glm::vec3( half_len, half_len, -half_len ));//top right
    vertex_data.push_back(center+glm::vec3( half_len, -half_len, -half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( half_len, half_len, half_len ));//top left
    //right face 2nd triangle
    vertex_data.push_back(center+glm::vec3( half_len, -half_len, -half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( half_len, -half_len, half_len ));//bottom left
    vertex_data.push_back(center+glm::vec3( half_len, half_len, half_len ));//top left
    //top face 1st triangle
    vertex_data.push_back(center+glm::vec3( half_len, half_len, -half_len ));//top right
    vertex_data.push_back(center+glm::vec3( half_len, half_len, half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( -half_len, half_len, -half_len ));//top left
    //top face 2nd triangle
    vertex_data.push_back(center+glm::vec3( half_len, half_len, half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( -half_len, half_len, half_len ));//bottom left
    vertex_data.push_back(center+glm::vec3( -half_len, half_len, -half_len ));//top left
    //bottom face 1st triangle
    vertex_data.push_back(center+glm::vec3( half_len, -half_len, -half_len ));//top right
    vertex_data.push_back(center+glm::vec3( half_len, -half_len, half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( -half_len, -half_len, -half_len ));//top left
    //bottom face 2nd triangle
    vertex_data.push_back(center+glm::vec3( half_len, -half_len, half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( -half_len, -half_len, half_len ));//bottom left
    vertex_data.push_back(center+glm::vec3( -half_len, -half_len, -half_len ));//top left
    
    
    /*//front face
    vertex_data.push_back(center+glm::vec3( half_len, half_len, half_len )); //top right
    vertex_data.push_back(center+glm::vec3( half_len, -half_len, half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( -half_len, -half_len, half_len ));//bottom left
    vertex_data.push_back(center+glm::vec3( -half_len, half_len, half_len ));//top left
    
    //back face
    vertex_data.push_back(center+glm::vec3( half_len, half_len, -half_len )); //top right
    vertex_data.push_back(center+glm::vec3( half_len, -half_len, -half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( -half_len, -half_len, -half_len ));//bottom left
    vertex_data.push_back(center+glm::vec3( -half_len, half_len,- half_len ));//top left
    
    //left face
    vertex_data.push_back(center+glm::vec3( -half_len, half_len, -half_len ));//top right
    vertex_data.push_back(center+glm::vec3( -half_len, -half_len, -half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( -half_len, -half_len, half_len ));//bottom left
    vertex_data.push_back(center+glm::vec3( -half_len, half_len, half_len ));//top left
    
    //right face
    vertex_data.push_back(center+glm::vec3( half_len, half_len, -half_len ));//top right
    vertex_data.push_back(center+glm::vec3( half_len, -half_len, -half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( half_len, -half_len, half_len ));//bottom left
    vertex_data.push_back(center+glm::vec3( half_len, half_len, half_len ));//top left
    
    //top face
    vertex_data.push_back(center+glm::vec3( half_len, half_len, -half_len ));//top right
    vertex_data.push_back(center+glm::vec3( half_len, half_len, half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( -half_len, half_len, half_len ));//bottom left
    vertex_data.push_back(center+glm::vec3( -half_len, half_len, -half_len ));//top left
    
    //bottom face
    vertex_data.push_back(center+glm::vec3( half_len, -half_len, -half_len ));//top right
    vertex_data.push_back(center+glm::vec3( half_len, -half_len, half_len ));//bottom right
    vertex_data.push_back(center+glm::vec3( -half_len, -half_len, half_len ));//bottom left
    vertex_data.push_back(center+glm::vec3( -half_len, -half_len, -half_len ));//top left*/
    
    
    //front face 1st triangle
    /*indices.push_back(0);
    indices.push_back(1);
    indices.push_back(3);
    //front face 2nd triangle
    indices.push_back(1);
    indices.push_back(2);
    indices.push_back(3);
    //back face 1st triangle
    indices.push_back(4);
    indices.push_back(5);
    indices.push_back(7);
    //back face 2nd triangle
    indices.push_back(5);
    indices.push_back(6);
    indices.push_back(7);
    //left face 1st triangle
    indices.push_back(7);
    indices.push_back(6);
    indices.push_back(3);
    //left face 2nd triangle
    indices.push_back(6);
    indices.push_back(2);
    indices.push_back(3);
    //right face 1st triangle
    indices.push_back(4);
    indices.push_back(5);
    indices.push_back(0);
    //right face 2nd triangle
    indices.push_back(5);
    indices.push_back(1);
    indices.push_back(0);
    //top face 1st triangle
    indices.push_back(4);
    indices.push_back(0);
    indices.push_back(7);
    //top face 2nd triangle
    indices.push_back(0);
    indices.push_back(3);
    indices.push_back(7);
    //bottom face 1st triangle
    indices.push_back(5);
    indices.push_back(1);
    indices.push_back(6);
    //bottom face 2nd face
    indices.push_back(1);
    indices.push_back(2);
    indices.push_back(6);*/

    
}

/*void Cube::set_ebo(){
    glGenVertexArrays(1,&cube_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cube_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices.data(), GL_STATIC_DRAW);
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
    
}*/

void Cube::set_buffer(const ShaderProgram& s){
    glGenVertexArrays(1,&cube_vao);
    glBindVertexArray( cube_vao );
    
    glGenBuffers( 1, &cube_vbo );
    glBindBuffer( GL_ARRAY_BUFFER, cube_vbo);
    //cout << "vertex data size is " << vertex_data.size();
    glBufferData( GL_ARRAY_BUFFER, sizeof(glm::vec3)*36,vertex_data.data(), GL_STATIC_DRAW );
    
    /*glGenVertexArrays(1,&cube_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cube_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices.data(), GL_STATIC_DRAW);*/
    
    //set_ebo();
    
    GLint posAttrib = s.getAttribLocation( "position" );
    glEnableVertexAttribArray( posAttrib );
    glVertexAttribPointer( posAttrib, 3, GL_FLOAT, GL_FALSE, 0, nullptr );
    
    // Reset state to prevent rogue code from messing with *my* stuff!
    glBindVertexArray( 0 );
    glBindBuffer( GL_ARRAY_BUFFER, 0 );
    //glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}

void Cube::draw(){
    glBindVertexArray(cube_vao);
    glBindBuffer(GL_ARRAY_BUFFER,cube_vbo);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    
    glBindVertexArray(0);
    glBindBuffer( GL_ARRAY_BUFFER, 0 );
   // glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
    
}

