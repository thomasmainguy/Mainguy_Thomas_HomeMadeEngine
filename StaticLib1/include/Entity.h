#ifndef THOMAS_ENTITY_H
#define THOMAS_ENTITY_H

#include <IGraphic.h>
#include <IInput.h>
#include <IAudio.h>
#include <ILog.h>
#include <ICollider.h>


namespace thomas
{
	class IScene;

	class Entity
	{
	public:
		virtual ~Entity() = default;

		virtual void Update(float aDeltaTime) {}
		virtual void Draw() {}

		virtual bool CanDraw() = 0;
		virtual bool CanUpdate() = 0;

		virtual void Start() = 0;
		virtual void Destroy() = 0;

		bool IsActive() const { return m_IsActive; }
		void SetActive(const bool aEnabled) { m_IsActive = aEnabled; }

	protected:

		//tout service fait ici
		IGraphic& GetGraphic() const; // shortcut por avoir acces plus vite
		IInput& GetInput() const;
		IAudio& GetAudio() const;
		IScene& GetScene() const;
		ILog& GetLog() const;
		ICollider& GetCollider() const;
		//---------
		bool m_IsActive{true};

	};
}
#endif

