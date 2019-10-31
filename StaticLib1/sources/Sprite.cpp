#include "..\include\Sprite.h"

void thomas::Sprite::Load(IGraphic & aGraphic, std::string & aFile)
{
	const unsigned tTexture = aGraphic.LoadTexture(aFile);
	if (tTexture != 0)
	{
		m_TextureId = tTexture;
		int tW, tH;
		aGraphic.GetTextureSize(m_TextureId, &tW, &tH);
		
		m_Destination.Set(0, 0, tW, tH);
		m_Source.Set(0, 0, tW, tH);
	}
}

void thomas::Sprite::Draw(IGraphic & aGraphic)
{
	aGraphic.Draw(m_TextureId, m_Source, m_Destination, m_Angle, m_Flip, m_Alpha);
}

void thomas::Sprite::Update(Transform * aTransform, float aDelta)
{
	if (aTransform != nullptr)
	{
		m_Destination.Set((int)aTransform->X, (int)aTransform->Y, (int)aTransform->Width, (int)aTransform->Height);
		m_Angle = aTransform->Angle;
		m_Flip = aTransform->Flipped;
	}
}
