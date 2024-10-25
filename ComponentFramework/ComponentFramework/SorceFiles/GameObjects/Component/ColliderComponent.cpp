//==================================================
// [ColliderComponent.h] �R���C�_�[�̃x�[�X
// ���ҁF�L�n�[��
//--------------------------------------------------
// �����F�������ł�
//==================================================


/*----- �C���N���[�h -----*/
#include "../../StdAfx.h"
#include "ColliderComponent.h"

using namespace DirectX::SimpleMath;

//--------------------------------------------------
// �R���X�g���N�^
//--------------------------------------------------
ColliderComponent::ColliderComponent(GameObject* owner, int updateOrder)
	:Component(owner, updateOrder)
{
}
	

//--------------------------------------------------
// �R���C�_�[�R���|�[�l���g
//--------------------------------------------------
ColliderComponent::~ColliderComponent(void)
{
}

//=======================================
//����������
//=======================================
void ColliderComponent::Init()
{
	// ���_�f�[�^
	std::vector<VERTEX_3D>	vertices;

	vertices.resize(4);

	vertices[0].position = Vector3(-10, 0, 10);
	vertices[1].position = Vector3(10, 0, 10);
	vertices[2].position = Vector3(-10, 0, -10);
	vertices[3].position = Vector3(10, 0, -10);

	vertices[0].color = Color(1, 1, 1, 1);
	vertices[1].color = Color(1, 1, 1, 1);
	vertices[2].color = Color(1, 1, 1, 1);
	vertices[3].color = Color(1, 1, 1, 1);

	vertices[0].uv = Vector2(0, 0);
	vertices[1].uv = Vector2(0, 0);
	vertices[2].uv = Vector2(0, 0);
	vertices[3].uv = Vector2(0, 0);

	// ���_�o�b�t�@����
	m_VertexBuffer.Create(vertices);

	// �C���f�b�N�X�o�b�t�@����
	std::vector<unsigned int> indices;
	indices.resize(4);

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 3;

	// �C���f�b�N�X�o�b�t�@����
	m_IndexBuffer.Create(indices);

}
