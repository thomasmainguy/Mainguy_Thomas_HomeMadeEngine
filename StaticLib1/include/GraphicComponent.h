#ifndef THOMAS_GRAPHICCOMPONENT_H
#define THOMAS_GRAPHICCOMPONENT_H

#include <string>
#include <Transformable.h>
#include <IGraphic.h>

namespace thomas
{
	class GraphicComponent : public Transformable
	{
	public:
		virtual ~GraphicComponent() = default;
		virtual void Load(IGraphic& aGraphic, std::string& aFile) = 0;
		virtual void Draw(IGraphic& aGraphic) = 0;


	};
}

#endif
