#ifndef THOMAS_ISERVICE_H
#define THOMAS_ISERVICE_H

namespace thomas
{
	class IService
	{

	public:
		virtual ~IService() = default;

		virtual bool Initialize() = 0;
		virtual void Clean() = 0;
	};
}

#endif