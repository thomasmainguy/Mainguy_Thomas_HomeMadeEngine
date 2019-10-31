#ifndef THOMAS_LOG_H
#define THOMAS_LOG_H

#include <ILog.h>
#include <string>

namespace thomas
{
	class Log final : public ILog
	{
	public:
		virtual ~Log() = default;
		virtual bool Initialize() override;
		virtual void Clean() override;

		virtual void LogUsingVS(const std::string & aMessage) override;
	};
}
#endif
