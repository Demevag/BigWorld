#ifndef HULL_MESH_HPP
#define HULL_MESH_HPP

// #include "visual_mesh.hpp"
#include "portal.hpp"
#include "mesh_piece.hpp"
#include "math/planeeq.hpp"
#include "cstdmf/bw_map.hpp"

BW_BEGIN_NAMESPACE

typedef SmartPointer<class HullMesh> HullMeshPtr;

namespace VisualManipulator {

    /**
     *	This class ...
     *
     *	@todo Document this class.
     */
    class Hull
    {
      public:
        Hull(MeshPiecePtr pBaseMesh)
          : pBaseMesh_(pBaseMesh)
        {
        }

        void        save(DataSectionPtr pSection);
        bool        hasPortal() const { return !portals_.empty(); }
        static void generateHullFromBB(DataSectionPtr     pVisualSection,
                                       const BoundingBox& bb);
        static void exportPortalsToBoundaries(DataSectionPtr pVisualSection,
                                              BW::vector<PortalPtr>& portals);

      private:
        BW::vector<PlaneEq>             planeEqs_;
        typedef BW::map<int, PortalPtr> PortalMap;
        PortalMap                       portals_;

        MeshPiecePtr pBaseMesh_;

        int  addUniquePlane(const PlaneEq& peq);
        int  findPlane(const PlaneEq& peq);
        bool isPortal(uint materialIndex);

        struct BiIndex
        {
            BiIndex();
            BiIndex(uint i1, uint i2);

            uint&       operator[](uint index);
            const uint& operator[](uint& index);

            uint i1;
            uint i2;
        };

        struct TriIndex
        {
            TriIndex();
            TriIndex(uint i1, uint i2, uint i3);

            uint&       operator[](uint index);
            const uint& operator[](uint& index);

            uint i1;
            uint i2;
            uint i3;
        };

        void      extractPlanesAndPortals(VertexVector&         vv,
                                          BW::vector<TriIndex>& faces);
        Triangle* findOriginalTriangle(TriIndex& face);

        bool makeConvex(VertexVector&         vertices,
                        BW::vector<TriIndex>& faces) const;
        bool mcCreateMaxTetrahedron(const VertexVector&   vertices,
                                    BW::vector<uint>&     verts,
                                    BW::vector<TriIndex>& faces,
                                    const float epsilon = 0.0001f) const;
        void mcRemoveVertex(const uint          vertIndex,
                            const VertexVector& vertices,
                            BW::vector<uint>&   verts,
                            const float         epsilon = 0.0001f) const;
        bool mcRemoveInsideVertices(const VertexVector&         vertices,
                                    BW::vector<uint>&           verts,
                                    const BW::vector<TriIndex>& faces) const;
        uint mcFindNextVert(const VertexVector&         vertices,
                            const BW::vector<uint>&     verts,
                            const BW::vector<TriIndex>& faces) const;
        void mcExpandHull(const uint            vertIndex,
                          const VertexVector&   vertices,
                          BW::vector<uint>&     verts,
                          BW::vector<TriIndex>& faces) const;
        bool mcIsInternalEdge(BW::vector<TriIndex>&   faces,
                              const BW::vector<uint>& frontFacing,
                              const uint              vertIndex1,
                              const uint              vertIndex2) const;
        void mcAddFaces(const uint              vertIndex,
                        const BW::vector<uint>& horizonVerts,
                        BW::vector<TriIndex>&   faces) const;
    };

};

BW_END_NAMESPACE

#endif // HULL_MESH_HPP
