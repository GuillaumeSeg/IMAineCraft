#ifndef _IMAC2GL3_TORCHE_
#define _IMAC2GL3_TORCHE_

#include <GL/glew.h>
#include "common.hpp"

namespace imac2gl3{
  class Torche{
 	  static const GLint POSITION_NUM_COMPONENTS = 3;
	  static const GLint NORMAL_NUM_COMPONENTS = 3;
	  static const GLint TEXCOORDS_NUM_COMPONENTS = 2;
	
	  static const GLsizei POSITION_OFFSET = 0;
	  static const GLsizei NORMAL_OFFSET = POSITION_NUM_COMPONENTS * sizeof(GLfloat);
	  static const GLsizei TEXCOORDS_OFFSET = (POSITION_NUM_COMPONENTS + NORMAL_NUM_COMPONENTS) * sizeof(GLfloat);
	
	  static const GLsizei VERTEX_BYTE_SIZE = (POSITION_NUM_COMPONENTS + NORMAL_NUM_COMPONENTS + TEXCOORDS_NUM_COMPONENTS) * sizeof(GLfloat);


    public:
		  Torche(GLfloat size);
		  ~Torche();
		  const GLvoid* getDataPointer() const; //Renvoie le tableau de données
		  GLsizei getVertexCount() const; //Renvoie le nombre de vertices
		  GLsizeiptr getByteSize() const; //Renvoie la taille du tableau en octets
		  GLint getPositionNumComponents() const; //Renvoie le nombre de composant pour la position
		  GLint getNormalNumComponents() const; //Renvoie le nombre de composant pour la normale
		  GLint getTexCoordsNumComponents() const; //Renvoie le nombre de composant pour les coordonnees de texture
		  GLsizei getVertexByteSize() const; //Renvoie la taille en octet d'un vertex
		  const GLvoid* getPositionOffset() const; //Renvoie l'offset de l'attribut position
		  const GLvoid* getNormalOffset() const; //Renvoie l'offset de l'attribut normale
		  const GLvoid* getTexCoordsOffset() const; //Renvoie l'offset de l'attribut coordonnees de texture
		  GLenum getDataType() const; //Renvoie le type de donnees d'une composante d'attribut

	  private:
		  ShapeVertex * m_pDataPointer; //Pointeur vers les données du tableau
		  GLsizei m_nVertexCount;
  
  };
}

#endif
