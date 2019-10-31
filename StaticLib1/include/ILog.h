#ifndef THOMAS_ILOG_H
#define THOMAS_ILOG_H

#include <IService.h>
#include <string>
namespace thomas
{
	class ILog : public IService
	{

	public:
		virtual ~ILog() = default;

		virtual bool Initialize() = 0;
		virtual void Clean() = 0;
		virtual void LogUsingVS(const std::string & aMessage) = 0;
	};
}

#endif
