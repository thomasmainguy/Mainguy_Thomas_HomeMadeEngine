#ifndef THOMAS_NULLLOG_H
#define THOMAS_NULLLOG_H

#include <ILog.h>
#include <string>

namespace thomas
{
	class NullLog final : public ILog
	{
	public:
		virtual ~NullLog() = default;
		virtual bool Initialize() override;
		virtual void Clean() override;


		// Inherited via ILog
		virtual void LogUsingVS(const std::string & aMessage) override;
	};
}
#endif