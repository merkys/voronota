#ifndef VIEWER_WIDGETS_WAITING_INDICATOR_H_
#define VIEWER_WIDGETS_WAITING_INDICATOR_H_

#include "../../dependencies/imgui/imgui_impl_glfw_gl3.h"

namespace voronota
{

namespace viewer
{

namespace widgets
{

class WaitingIndicator
{
public:
	WaitingIndicator() :
		decided_(false),
		activated_(false),
		executed_(0)
	{
	}

	bool decided() const
	{
		return (decided_);
	}

	bool activated() const
	{
		return (decided_ && activated_);
	}

	bool executed() const
	{
		return (decided_ && activated_ && executed_>1);
	}

	void set_activated(const bool activated)
	{
		decided_=true;
		activated_=activated;
	}

	void reset()
	{
		decided_=false;
		activated_=false;
		executed_=0;
	}

	void execute(const int window_width, const int window_height)
	{
		if(!activated_)
		{
			return;
		}

		const int label_width=150;
		const int label_height=30;
		const int label_x_pos=(window_width/2)-(label_width/2);
		const int label_y_pos=(window_height/2)-(label_height/2);

		ImGui::SetNextWindowPos(ImVec2(label_x_pos, label_y_pos));
		ImGui::SetNextWindowSize(ImVec2(label_width, label_height));
		ImGui::Begin("Waiting", 0, ImVec2(0, 0), 0.75f, ImGuiWindowFlags_NoTitleBar|ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoSavedSettings);
		ImGui::Text("Please wait ...");
		ImGui::End();

		executed_++;
	}

private:
	bool decided_;
	bool activated_;
	int executed_;
};

}

}

}

#endif /* VIEWER_WIDGETS_WAITING_INDICATOR_H_ */