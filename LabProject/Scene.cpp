#include "stdafx.h"
#include "Scene.h"

default_random_engine dre;
uniform_int_distribution <int> uid{ -30,30 };

CScene::CScene()
{
}

CScene::~CScene()
{
}

void CScene::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
}

void CScene::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID)
	{
		case WM_KEYDOWN:
			switch (wParam)
			{
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
				{
					CExplosiveObject *pExplosiveObject = (CExplosiveObject *)m_ppObjects[int(wParam - '1')];
					pExplosiveObject->m_bBlowingUp = true;
					break;
				}
				case 'A':
					for (int i = 0; i < m_nObjects; i++)
					{
						CExplosiveObject *pExplosiveObject = (CExplosiveObject *)m_ppObjects[i];
						pExplosiveObject->m_bBlowingUp = true;
					}
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}

void CScene::BuildObjects()
{
	CExplosiveObject::PrepareExplosion();

	float fHalfWidth = 45.0f, fHalfHeight = 45.0f, fHalfDepth = 110.0f;
	CWallMesh *pWallCubeMesh = new CWallMesh(fHalfWidth * 2.0f, fHalfHeight * 2.0f, fHalfDepth * 2.0f, 30);

	m_pWallsObject = new CWallsObject();
	m_pWallsObject->SetPosition(0.0f, 0.0f, 0.0f);
	m_pWallsObject->SetMesh(pWallCubeMesh);
	m_pWallsObject->SetColor(RGB(0, 0, 0));
	m_pWallsObject->m_pxmf4WallPlanes[0] = XMFLOAT4(+1.0f, 0.0f, 0.0f, fHalfWidth);
	m_pWallsObject->m_pxmf4WallPlanes[1] = XMFLOAT4(-1.0f, 0.0f, 0.0f, fHalfWidth);
	m_pWallsObject->m_pxmf4WallPlanes[2] = XMFLOAT4(0.0f, +1.0f, 0.0f, fHalfHeight);
	m_pWallsObject->m_pxmf4WallPlanes[3] = XMFLOAT4(0.0f, -1.0f, 0.0f, fHalfHeight);
	m_pWallsObject->m_pxmf4WallPlanes[4] = XMFLOAT4(0.0f, 0.0f, +1.0f, fHalfDepth);
	m_pWallsObject->m_pxmf4WallPlanes[5] = XMFLOAT4(0.0f, 0.0f, -1.0f, fHalfDepth);
	m_pWallsObject->m_xmOOBBPlayerMoveCheck = BoundingOrientedBox(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(fHalfWidth, fHalfHeight, fHalfDepth * 0.05f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f));

	CCubeMesh *pObjectCubeMesh = new CCubeMesh(4.0f, 4.0f, 8.0f);
	CCubeMesh* pObjectSmallCubeMesh = new CCubeMesh(0.5f, 0.5f, 0.5f);

	m_nObjects = 21;
	m_ppObjects = new CGameObject*[m_nObjects];

	m_ppObjects[0] = new CExplosiveObject();
	m_ppObjects[0]->SetMesh(pObjectCubeMesh);
	m_ppObjects[0]->SetColor(RGB(255, 0, 0));
	m_ppObjects[0]->SetPosition(-13.5f, 0.0f, 350.0f);
	m_ppObjects[0]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[0]->SetMovingSpeed(9.5f);

	m_ppObjects[1] = new CExplosiveObject();
	m_ppObjects[1]->SetMesh(pObjectCubeMesh);
	m_ppObjects[1]->SetColor(RGB(0, 0, 255));
	m_ppObjects[1]->SetPosition(+13.5f, 0.0f, 440.0f);
	m_ppObjects[1]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[1]->SetMovingSpeed(6.8f);

	m_ppObjects[2] = new CExplosiveObject();
	m_ppObjects[2]->SetMesh(pObjectCubeMesh);
	m_ppObjects[2]->SetColor(RGB(0, 255, 0));
	m_ppObjects[2]->SetPosition(0.0f, 0.0f, 400.0f);
	m_ppObjects[2]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[2]->SetMovingSpeed(3.2f);

	m_ppObjects[3] = new CExplosiveObject();
	m_ppObjects[3]->SetMesh(pObjectCubeMesh);
	m_ppObjects[3]->SetColor(RGB(0, 255, 255));
	m_ppObjects[3]->SetPosition(0.0f, 0.0f, 370.0f);
	m_ppObjects[3]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[3]->SetMovingSpeed(20.4f);

	m_ppObjects[4] = new CExplosiveObject();
	m_ppObjects[4]->SetMesh(pObjectCubeMesh);
	m_ppObjects[4]->SetColor(RGB(128, 0, 255));
	m_ppObjects[4]->SetPosition(10.0f, 0.0f, 130.0f);
	m_ppObjects[4]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[4]->SetMovingSpeed(26.4f);

	m_ppObjects[5] = new CExplosiveObject();
	m_ppObjects[5]->SetMesh(pObjectCubeMesh);
	m_ppObjects[5]->SetColor(RGB(255, 0, 255));
	m_ppObjects[5]->SetPosition(-10.0f, 0.0f, 550.0f);
	m_ppObjects[5]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[5]->SetMovingSpeed(30.9f);

	m_ppObjects[6] = new CExplosiveObject();
	m_ppObjects[6]->SetMesh(pObjectCubeMesh);
	m_ppObjects[6]->SetColor(RGB(255, 0, 255));
	m_ppObjects[6]->SetPosition(-10.0f, 0.0f, 320.0f);
	m_ppObjects[6]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[6]->SetMovingSpeed(14.7f);

	m_ppObjects[7] = new CExplosiveObject();
	m_ppObjects[7]->SetMesh(pObjectCubeMesh);
	m_ppObjects[7]->SetColor(RGB(255, 0, 128));
	m_ppObjects[7]->SetPosition(-10.0f, 0.0f, 190.0f);
	m_ppObjects[7]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[7]->SetMovingSpeed(6.6f);

	m_ppObjects[8] = new CExplosiveObject();
	m_ppObjects[8]->SetMesh(pObjectCubeMesh);
	m_ppObjects[8]->SetColor(RGB(128, 0, 255));
	m_ppObjects[8]->SetPosition(-15.0f, 0.0f, 170.0f);
	m_ppObjects[8]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[8]->SetMovingSpeed(40.0f);

	m_ppObjects[9] = new CExplosiveObject();
	m_ppObjects[9]->SetMesh(pObjectCubeMesh);
	m_ppObjects[9]->SetColor(RGB(255, 64, 64));
	m_ppObjects[9]->SetPosition(+15.0f, 0.0f, 154.0f);
	m_ppObjects[9]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[9]->SetMovingSpeed(9.3f);

	m_ppObjects[10] = new CExplosiveObject();
	m_ppObjects[10]->SetMesh(pObjectCubeMesh);
	m_ppObjects[10]->SetColor(RGB(255, 64, 64));
	m_ppObjects[10]->SetPosition(+15.0f, 0.0f, 254.0f);
	m_ppObjects[10]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[10]->SetMovingSpeed(12.0f);

	m_ppObjects[11] = new CExplosiveObject();
	m_ppObjects[11]->SetMesh(pObjectCubeMesh);
	m_ppObjects[11]->SetColor(RGB(255, 64, 64));
	m_ppObjects[11]->SetPosition(+15.0f, 0.0f, 254.0f);
	m_ppObjects[11]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[11]->SetMovingSpeed(28.0f);

	m_ppObjects[12] = new CExplosiveObject();
	m_ppObjects[12]->SetMesh(pObjectCubeMesh);
	m_ppObjects[12]->SetColor(RGB(255, 64, 64));
	m_ppObjects[12]->SetPosition(+15.0f, 0.0f, 254.0f);
	m_ppObjects[12]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[12]->SetMovingSpeed(11.0f);

	m_ppObjects[13] = new CExplosiveObject();
	m_ppObjects[13]->SetMesh(pObjectCubeMesh);
	m_ppObjects[13]->SetColor(RGB(255, 64, 64));
	m_ppObjects[13]->SetPosition(+15.0f, 0.0f, 254.0f);
	m_ppObjects[13]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[13]->SetMovingSpeed(12.0f);

	m_ppObjects[14] = new CExplosiveObject();
	m_ppObjects[14]->SetMesh(pObjectCubeMesh);
	m_ppObjects[14]->SetColor(RGB(255, 64, 64));
	m_ppObjects[14]->SetPosition(+15.0f, 0.0f, 260.0f);
	m_ppObjects[14]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[14]->SetMovingSpeed(14.5f);

	m_ppObjects[15] = new CItemObject();
	m_ppObjects[15]->SetMesh(pObjectSmallCubeMesh);
	m_ppObjects[15]->SetColor(RGB(255, 255, 255));
	m_ppObjects[15]->SetPosition(+15.0f, 0.0f, 200.0f);
	m_ppObjects[15]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[15]->SetMovingSpeed(10.0f);




	m_ppObjects[16] = new CCoinObject(uid(dre));
	m_ppObjects[16]->SetMesh(pObjectSmallCubeMesh);
	m_ppObjects[16]->SetColor(RGB(255, 255, 0));
	m_ppObjects[16]->SetPosition(0.0f, 0.0f, 200.0f);
	m_ppObjects[16]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[16]->SetMovingSpeed(0.0f);

	m_ppObjects[17] = new CCoinObject();
	m_ppObjects[17]->SetMesh(pObjectSmallCubeMesh);
	m_ppObjects[17]->SetColor(RGB(255, 255, 0));
	m_ppObjects[17]->SetPosition(+15.0f, 0.0f, 240.0f);
	m_ppObjects[17]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[17]->SetMovingSpeed(0.0f);

	m_ppObjects[18] = new CCoinObject();
	m_ppObjects[18]->SetMesh(pObjectSmallCubeMesh);
	m_ppObjects[18]->SetColor(RGB(255, 255, 0));
	m_ppObjects[18]->SetPosition(+15.0f, 0.0f, 280.0f);
	m_ppObjects[18]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[18]->SetMovingSpeed(0.0f);

	m_ppObjects[19] = new CCoinObject();
	m_ppObjects[19]->SetMesh(pObjectSmallCubeMesh);
	m_ppObjects[19]->SetColor(RGB(255, 255, 0));
	m_ppObjects[19]->SetPosition(+15.0f, 0.0f, 320.0f);
	m_ppObjects[19]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[19]->SetMovingSpeed(0.0f);

	m_ppObjects[20] = new CCoinObject();
	m_ppObjects[20]->SetMesh(pObjectSmallCubeMesh);
	m_ppObjects[20]->SetColor(RGB(255, 255, 0));
	m_ppObjects[20]->SetPosition(+15.0f, 0.0f, 360.0f);
	m_ppObjects[20]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	m_ppObjects[20]->SetMovingSpeed(0.0f);
}

void CScene::ReleaseObjects()
{
	if (CExplosiveObject::m_pExplosionMesh) CExplosiveObject::m_pExplosionMesh->Release();

	for (int i = 0; i < m_nObjects; i++) if (m_ppObjects[i]) delete m_ppObjects[i];
	if (m_ppObjects) delete[] m_ppObjects;

	if (m_pWallsObject) delete m_pWallsObject;
}

CGameObject *CScene::PickObjectPointedByCursor(int xClient, int yClient, CCamera *pCamera)
{
	XMFLOAT3 xmf3PickPosition;
	xmf3PickPosition.x = (((2.0f * xClient) / pCamera->m_d3dViewport.Width) - 1) / pCamera->m_xmf4x4Projection._11;
	xmf3PickPosition.y = -(((2.0f * yClient) / pCamera->m_d3dViewport.Height) - 1) / pCamera->m_xmf4x4Projection._22;
	xmf3PickPosition.z = 1.0f;

	XMVECTOR xmvPickPosition = XMLoadFloat3(&xmf3PickPosition);
	XMMATRIX xmmtxView = XMLoadFloat4x4(&pCamera->m_xmf4x4View);

	int nIntersected = 0;
	float fNearestHitDistance = FLT_MAX;
	CGameObject *pNearestObject = NULL;
	for (int i = 0; i < m_nObjects; i++)
	{
		float fHitDistance = FLT_MAX;
		nIntersected = m_ppObjects[i]->PickObjectByRayIntersection(xmvPickPosition, xmmtxView, &fHitDistance);
		if ((nIntersected > 0) && (fHitDistance < fNearestHitDistance))
		{
			fNearestHitDistance = fHitDistance;
			pNearestObject = m_ppObjects[i];
		}
	}
	return(pNearestObject);
}


void CScene::CheckObjectByPlayerCollisions()
{
	for (int i = 0; i < m_nObjects; i++)
	{
		ContainmentType containType = m_pPlayer->m_xmOOBB.Contains(m_ppObjects[i]->m_xmOOBB);
		if (m_ppObjects[i]->m_xmOOBB.Intersects(m_pPlayer->m_xmOOBB))
		{
			switch (m_ppObjects[i]->type) {
			case ObjectType::ITEM :
				m_ppObjects[i]->m_bVisible = false;
				m_pPlayer->ActionBoost();
				break;
			case ObjectType::OBJECT :
				if (!m_pPlayer->m_isBooster) {
					m_pPlayer->m_pSpeed = SPEED_DEFAULT;
					dynamic_cast<CExplosiveObject*>(m_ppObjects[i])->m_fExplosionSpeed = 20.0f;
				}
				else {
					dynamic_cast<CExplosiveObject*>(m_ppObjects[i])->m_fExplosionSpeed = 100.0f;
				}
				dynamic_cast<CExplosiveObject*>(m_ppObjects[i])->m_bBlowingUp = true;
				break;
			case ObjectType::COIN:
				// 점수가 얻어지겠지?
				m_pPlayer->m_coin++;
				
				m_ppObjects[i]->m_bVisible = false;
				break;
			}
		}
	}
}

void CScene::CheckPlayerByWallCollision()
{
	BoundingOrientedBox xmOOBBPlayerMoveCheck;
	m_pWallsObject->m_xmOOBBPlayerMoveCheck.Transform(xmOOBBPlayerMoveCheck, XMLoadFloat4x4(&m_pWallsObject->m_xmf4x4World));
	XMStoreFloat4(&xmOOBBPlayerMoveCheck.Orientation, XMQuaternionNormalize(XMLoadFloat4(&xmOOBBPlayerMoveCheck.Orientation)));

	// [DEV] wall이 플레이어 따라 오지 않도록 z값만 따라옴
	XMFLOAT3 wallPosition = XMFLOAT3(0,0, m_pPlayer->m_xmf3Position.z);
	if (!xmOOBBPlayerMoveCheck.Intersects(m_pPlayer->m_xmOOBB)) m_pWallsObject->SetPosition(wallPosition);
}

void CScene::CheckObjectByBulletCollisions()
{
	CBulletObject **ppBullets = ((CAirplanePlayer *)m_pPlayer)->m_ppBullets;
	for (int i = 0; i < m_nObjects; i++)
	{
		for (int j = 0; j < BULLETS; j++)
		{
			if (ppBullets[j]->m_bActive && m_ppObjects[i]->m_xmOOBB.Intersects(ppBullets[j]->m_xmOOBB)) 
			{
				CExplosiveObject *pExplosiveObject = (CExplosiveObject *)m_ppObjects[i];
				pExplosiveObject->m_bBlowingUp = true;
				ppBullets[j]->m_bActive = false;
			}
		}
	}
}

void CScene::Animate(float fElapsedTime)
{
	m_pWallsObject->Animate(fElapsedTime);
	int bufferDistance = 10;
	for (int i = 0; i < m_nObjects; i++) {
		m_ppObjects[i]->Animate(fElapsedTime);
		if (m_ppObjects[i]->GetPosition().z < m_pPlayer->GetPosition().z - bufferDistance) {
			if (m_ppObjects[i]->type == ObjectType::COIN)
			{
				if (dynamic_cast<CCoinObject*>(m_ppObjects[i])->m_bFirstCoin) {
					dynamic_cast<CCoinObject*>(m_ppObjects[i])->m_xPosition = uid(dre);
				}
				m_ppObjects[i]->SetPosition(0, 0, m_pPlayer->GetPosition().z + 500);
			}
			else {
				m_ppObjects[i]->SetPosition(uid(dre), 0,m_pPlayer->GetPosition().z + 500 + (uid(dre) * 3));
			}
			if(m_ppObjects[i]->type == ObjectType::OBJECT)
				dynamic_cast<CExplosiveObject*>(m_ppObjects[i])->m_bBlowingUp = false;
		m_ppObjects[i]->m_bVisible = true;
		}
	}
	CheckPlayerByWallCollision();

	CheckObjectByPlayerCollisions();

	CheckObjectByBulletCollisions();
}

void CScene::Render(HDC hDCFrameBuffer, CCamera *pCamera)
{
	m_pWallsObject->Render(hDCFrameBuffer, pCamera);

	for (int i = 0; i < m_nObjects; i++) {
		if (m_ppObjects[i]->m_bVisible) {
			m_ppObjects[i]->Render(hDCFrameBuffer, pCamera);
		}
	}
}

