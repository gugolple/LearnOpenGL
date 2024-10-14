#include "shader_unit.hpp"

std::string
loadShader(const char* filename)
{
  // Manage relative path
  std::filesystem::path p = std::filesystem::current_path() / filename;
  // Sanity check that the shader exists
  assert(std::filesystem::status(p).type() !=
         std::filesystem::file_type::not_found);
  std::ifstream myfile(filename);

  std::string buffer((std::istreambuf_iterator<char>(myfile)),
                     (std::istreambuf_iterator<char>()));
  return buffer;
}

int
check_status_program(unsigned int element, GLenum pname, const char* message)
{
  int success = 0;
  char infoLog[512];
  infoLog[0] = '\0';
  glGetProgramiv(element, pname, &success);
  if (!success) {
    glGetShaderInfoLog(element, 512, NULL, infoLog);
    std::cout << element << " - " << message << infoLog;
  }
  assert(success);
  return success;
}

int
check_status_shader(unsigned int element, GLenum pname, const char* message)
{
  int success = 0;
  char infoLog[512];
  infoLog[0] = '\0';
  glGetShaderiv(element, pname, &success);
  if (!success) {
    glGetShaderInfoLog(element, 512, NULL, infoLog);
    std::cout << element << " - " << message << infoLog;
  }
  assert(success);
  return success;
}

GLuint
compile_shader(const char* shaderFile, GLenum shaderType)
{
  std::string shaderSource = loadShader(shaderFile);

  // Set shader
  GLuint shader = 0;
  shader = glCreateShader(shaderType);

  // Needed so gcc/c++ does understand correctly the types
  const char* buf = shaderSource.c_str();
  glShaderSource(shader, 1, &buf, NULL);
  glCompileShader(shader);

  // Check compilation
  check_status_shader(
    shader, GL_COMPILE_STATUS, "ERROR::SHADER::COMPILATION_FAILED\n");

  std::cout << shaderFile << std::endl;

  return shader;
}

ShaderUnit::ShaderUnit(const char* filename, GLenum shaderType)
  : shader(compile_shader(filename, shaderType))
  , shaderType(shaderType)
{
}

GLuint
ShaderUnit::getShader() const
{
  return this->shader;
}

GLenum
ShaderUnit::getShaderType() const
{
  return this->shaderType;
}

ShaderUnit::~ShaderUnit()
{
  if (this->shader) {
    glDeleteShader(this->shader);
  }
}

ShaderUnit::ShaderUnit(ShaderUnit&& other)
  : shader(other.shader)
  , shaderType(other.shaderType)
{
  other.shader = 0;
}
