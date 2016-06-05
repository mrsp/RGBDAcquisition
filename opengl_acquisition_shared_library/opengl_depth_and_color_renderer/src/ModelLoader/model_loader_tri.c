#include "model_loader_tri.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#if HAVE_OBJ_CODE_AVAILIABLE
int convertObjToTri(struct TRI_Model * tri , struct OBJ_Model * obj)
{
   if (tri==0) { return 0; }
   if (obj==0) { return 0; }

   unsigned int i=0,j=0,pos=0,posTex=0;

       tri->header.triType=TRI_LOADER_VERSION;
       tri->header.numberOfVertices      = obj->numGroups * obj->numFaces * 3 ;
       tri->header.numberOfNormals       = obj->numGroups * obj->numFaces * 3 ;
       tri->header.numberOfColors        = obj->numGroups * obj->numFaces * 3 ;
       tri->header.numberOfTextureCoords = obj->numGroups * obj->numFaces * 2 ;
       tri->header.numberOfIndices   = 0; // We go full flat when converting an obj image
       tri->indices                  = 0; // We go full flat when converting an obj image
       tri->header.drawType = 0;          // Triangles

       tri->textureCoords =   malloc(sizeof(float)  * tri->header.numberOfVertices);
       tri->vertices = malloc(sizeof(float) *  tri->header.numberOfVertices);
       tri->normal = malloc(sizeof(float) *  tri->header.numberOfNormals);
       tri->colors = malloc(sizeof(float) *  tri->header.numberOfColors);
       for(i=0; i<obj->numGroups; i++)
	   {
        for(j=0; j<obj->groups[i].numFaces; j++)
			{
			  tri->vertices[pos++] = obj->vertexList[ obj->faceList[ obj->groups[i].faceList[j]].v[0]].x;
			  tri->vertices[pos++] = obj->vertexList[ obj->faceList[ obj->groups[i].faceList[j]].v[0]].y;
              tri->vertices[pos++] = obj->vertexList[ obj->faceList[ obj->groups[i].faceList[j]].v[0]].z;

              tri->vertices[pos++] = obj->vertexList[ obj->faceList[ obj->groups[i].faceList[j]].v[1]].x;
              tri->vertices[pos++] = obj->vertexList[ obj->faceList[ obj->groups[i].faceList[j]].v[1]].y;
              tri->vertices[pos++] = obj->vertexList[ obj->faceList[ obj->groups[i].faceList[j]].v[1]].z;

              tri->vertices[pos++] = obj->vertexList[ obj->faceList[ obj->groups[i].faceList[j]].v[2]].x;
              tri->vertices[pos++] = obj->vertexList[ obj->faceList[ obj->groups[i].faceList[j]].v[2]].y;
              tri->vertices[pos++] = obj->vertexList[ obj->faceList[ obj->groups[i].faceList[j]].v[2]].z;
			}
		}

        pos=0;
        for(i=0; i<obj->numGroups; i++)
		{
         for(j=0; j<obj->groups[i].numFaces; j++)
			{
              if( obj->groups[i].hasNormals)
                  {
                     tri->normal[pos++] = obj->normalList[ obj->faceList[ obj->groups[i].faceList[j]].n[0]].n1;
                     tri->normal[pos++] = obj->normalList[ obj->faceList[ obj->groups[i].faceList[j]].n[0]].n2;
                     tri->normal[pos++] = obj->normalList[ obj->faceList[ obj->groups[i].faceList[j]].n[0]].n3;

                     tri->normal[pos++] = obj->normalList[ obj->faceList[ obj->groups[i].faceList[j]].n[1]].n1;
                     tri->normal[pos++] = obj->normalList[ obj->faceList[ obj->groups[i].faceList[j]].n[1]].n2;
                     tri->normal[pos++] = obj->normalList[ obj->faceList[ obj->groups[i].faceList[j]].n[1]].n3;


                     tri->normal[pos++] = obj->normalList[ obj->faceList[ obj->groups[i].faceList[j]].n[2]].n1;
                     tri->normal[pos++] = obj->normalList[ obj->faceList[ obj->groups[i].faceList[j]].n[2]].n2;
                     tri->normal[pos++] = obj->normalList[ obj->faceList[ obj->groups[i].faceList[j]].n[2]].n3;
                  }
				else
				 {
					tri->normal[pos++] = obj->faceList[ obj->groups[i].faceList[j]].fc_normal.n1;
                    tri->normal[pos++] = obj->faceList[ obj->groups[i].faceList[j]].fc_normal.n2;
                    tri->normal[pos++] = obj->faceList[ obj->groups[i].faceList[j]].fc_normal.n3;

                    tri->normal[pos++] = obj->faceList[ obj->groups[i].faceList[j]].fc_normal.n1;
                    tri->normal[pos++] = obj->faceList[ obj->groups[i].faceList[j]].fc_normal.n2;
                    tri->normal[pos++] = obj->faceList[ obj->groups[i].faceList[j]].fc_normal.n3;

                    tri->normal[pos++] = obj->faceList[ obj->groups[i].faceList[j]].fc_normal.n1;
                    tri->normal[pos++] = obj->faceList[ obj->groups[i].faceList[j]].fc_normal.n2;
                    tri->normal[pos++] = obj->faceList[ obj->groups[i].faceList[j]].fc_normal.n3;
				}
			}//FOR J
		}

      if (obj->texList!=0)
      {
      posTex=0;
	  for(i=0; i<obj->numGroups; i++)
	   {
        for(j=0; j<obj->groups[i].numFaces; j++)
			{
              tri->textureCoords[posTex++] =  obj->texList[ obj->faceList[ obj->groups[i].faceList[j]].t[0]].u;
              tri->textureCoords[posTex++] =  obj->texList[ obj->faceList[ obj->groups[i].faceList[j]].t[0]].v;
              tri->textureCoords[posTex++] =  obj->texList[ obj->faceList[ obj->groups[i].faceList[j]].t[1]].u;
              tri->textureCoords[posTex++] =  obj->texList[ obj->faceList[ obj->groups[i].faceList[j]].t[1]].v;
              tri->textureCoords[posTex++] =  obj->texList[ obj->faceList[ obj->groups[i].faceList[j]].t[2]].u;
              tri->textureCoords[posTex++] =  obj->texList[ obj->faceList[ obj->groups[i].faceList[j]].t[2]].v;
			}
		}
      }



      pos=0;
      if (obj->colorList!=0)
      {
       for(i=0; i<obj->numGroups; i++)
	   {
        for(j=0; j<obj->groups[i].numFaces; j++)
			{
			  tri->colors[pos++] = obj->colorList[ obj->faceList[ obj->groups[i].faceList[j]].v[0]].r;
			  tri->colors[pos++] = obj->colorList[ obj->faceList[ obj->groups[i].faceList[j]].v[0]].g;
              tri->colors[pos++] = obj->colorList[ obj->faceList[ obj->groups[i].faceList[j]].v[0]].b;

              tri->colors[pos++] = obj->colorList[ obj->faceList[ obj->groups[i].faceList[j]].v[1]].r;
              tri->colors[pos++] = obj->colorList[ obj->faceList[ obj->groups[i].faceList[j]].v[1]].g;
              tri->colors[pos++] = obj->colorList[ obj->faceList[ obj->groups[i].faceList[j]].v[1]].b;

              tri->colors[pos++] = obj->colorList[ obj->faceList[ obj->groups[i].faceList[j]].v[2]].r;
              tri->colors[pos++] = obj->colorList[ obj->faceList[ obj->groups[i].faceList[j]].v[2]].g;
              tri->colors[pos++] = obj->colorList[ obj->faceList[ obj->groups[i].faceList[j]].v[2]].b;
			}
		}
      }

  return 1;
}
#endif // HAVE_OBJ_CODE_AVAILIABLE

int loadModelTri(const char * filename , struct TRI_Model * triModel)
{
  fprintf(stderr,"Reading TRI model -> %s \n",filename );
  FILE *fd=0;
  fd = fopen(filename,"rb");
  if (fd!=0)
    {
        size_t n;

        n = fread(&triModel->header , sizeof(struct TRI_Header), 1 , fd);
        if (triModel->header.floatSize!=sizeof(float)) { fprintf(stderr,"Size of float (%u/%u) is different , cannot load \n",triModel->header.floatSize,sizeof(float)); return 0; }
        if (triModel->header.triType != TRI_LOADER_VERSION ) { fprintf(stderr,"Incompatible triloader file , cannot load \n",triModel->header.floatSize,sizeof(float)); return 0; }


        if (triModel->header.numberOfVertices)
        {
         fprintf(stderr,"Reading %u bytes of vertex\n",sizeof(float) * 3 * triModel->header.numberOfVertices);
         triModel->vertices = ( float * ) malloc ( sizeof(float) * 3 * triModel->header.numberOfVertices );
         n = fread(triModel->vertices , sizeof(float), 3 * triModel->header.numberOfVertices , fd);
        } else {  fprintf(stderr,"No vertices specified \n"); }

        if (triModel->header.numberOfNormals)
        {
         fprintf(stderr,"Reading %u bytes of normal\n",sizeof(float) * 3 * triModel->header.numberOfNormals);
         triModel->normal = ( float * ) malloc ( sizeof(float) * 3 * triModel->header.numberOfNormals );
         n = fread(triModel->normal , sizeof(float), 3 * triModel->header.numberOfNormals , fd);
        } else {  fprintf(stderr,"No normals specified \n"); }


        if (triModel->header.numberOfTextureCoords)
        {
        fprintf(stderr,"Reading %u bytes of textures\n",sizeof(float) * 2 *triModel->header.numberOfTextureCoords);
        triModel->textureCoords = ( float * ) malloc ( sizeof(float) * 2 * triModel->header.numberOfTextureCoords );
        n = fread(triModel->textureCoords , sizeof(float), 2 * triModel->header.numberOfTextureCoords , fd);
        }  else {  fprintf(stderr,"No texture coords specified \n"); }

        if (triModel->header.numberOfColors)
        {
         fprintf(stderr,"Reading %u bytes of colors\n",sizeof(float) * 3 *triModel->header.numberOfColors);
         triModel->colors = ( float * ) malloc ( sizeof(float) * 3 * triModel->header.numberOfColors );
         n = fread(triModel->colors , sizeof(float), 3 * triModel->header.numberOfColors , fd);
        } else {  fprintf(stderr,"No colors specified \n"); }

        if (triModel->header.numberOfIndices)
        {
         fprintf(stderr,"Reading %u bytes of indices\n",sizeof(float) * 3 *triModel->header.numberOfIndices);
         triModel->indices = ( float * ) malloc ( sizeof(float) * 3 * triModel->header.numberOfIndices );
         n = fread(triModel->indices , sizeof(float), 3 * triModel->header.numberOfIndices , fd);
        } else {  fprintf(stderr,"No indices specified \n"); }


        fclose(fd);
        return 1;
    }
  return 0;
}




int saveModelTri(const char * filename , struct TRI_Model * triModel)
{
  fprintf(stderr,"Writing TRI model -> %s \n",filename );
  unsigned int i=0;
  FILE *fd=0;
  fd = fopen(filename,"wb");
  if (fd!=0)
    {
        triModel->header.triType = TRI_LOADER_VERSION;
        triModel->header.floatSize =(unsigned int ) sizeof(float);
        fwrite (&triModel->header        , sizeof(struct TRI_Header), 1 , fd);

        if (triModel->header.numberOfVertices)
        {
         fprintf(stderr,"Writing %u bytes of vertex\n", sizeof(float) * 3 * triModel->header.numberOfVertices);
         fwrite (triModel->vertices , 3*sizeof(float), triModel->header.numberOfVertices, fd);
        }

        if (triModel->header.numberOfNormals)
        {
        fprintf(stderr,"Writing %u bytes of normal\n",sizeof(float) * 3 * triModel->header.numberOfNormals);
        fwrite (triModel->normal         , 3*sizeof(float), triModel->header.numberOfNormals  , fd);
        }

        if (triModel->header.numberOfTextureCoords)
        {
        fprintf(stderr,"Writing %u bytes of texture coords\n", sizeof(float) * 2 * triModel->header.numberOfTextureCoords);
        fwrite (triModel->textureCoords , 2*sizeof(float), triModel->header.numberOfTextureCoords, fd);
        }

        if (triModel->header.numberOfColors)
        {
        fprintf(stderr,"Writing %u bytes of colors\n", sizeof(float) * 3 * triModel->header.numberOfColors);
        fwrite (triModel->colors , 3*sizeof(float), triModel->header.numberOfColors, fd);
        }

        if (triModel->header.numberOfIndices)
        {
        fprintf(stderr,"Writing %u bytes of indices\n", sizeof(float) * 3 * triModel->header.numberOfIndices);
        fwrite (triModel->indices , 3*sizeof(float), triModel->header.numberOfIndices, fd);
        }

        fflush(fd);
        fclose(fd);
        return 1;
    }
  return 0;
}


/*
int saveModelTriHeader(const char * filename , struct TRI_Model * triModel)
{

  char headerOut[256];
  snprintf(headerOut,256,"%s.h",filename);

  unsigned int i=0;
  FILE *fd=0;
  fd = fopen(headerOut,"w");
  if (fd!=0)
    {

        fprintf(fd,"const float %sVertices[] = { \n",filename);
        for (i=0; i<triModel->header.numberOfVertices; i++)
        {
          fprintf(
                   fd,"%0.4f , %0.4f , %0.4f ",
                   triModel->vertices[(i*3)+0],
                   triModel->vertices[(i*3)+1],
                   triModel->vertices[(i*3)+2]
                  );

          if (i+1<triModel->header.numberOfVertices) { fprintf(fd,", \n"); }
        }
        fprintf(fd,"}; \n\n");


        fprintf(fd,"const float %sNormals[] = { \n",filename);
        for (i=0; i<triModel->header.numberOfNormals; i++)
        {
           fprintf(
                   fd,"%0.4f , %0.4f , %0.4f ",
                   triModel->normal[(i*3)+0],
                   triModel->normal[(i*3)+1],
                   triModel->normal[(i*3)+2]
                  );
          if (i+1<triModel->header.numberOfNormals) { fprintf(fd,", \n"); }
        }
        fprintf(fd,"}; \n\n");

       fflush(fd);
       fclose(fd);
       return 1;
    }
  return 0;
}
*/




