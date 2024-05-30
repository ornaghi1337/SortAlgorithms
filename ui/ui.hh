#pragma once
#include <d3d9.h>
#include "../imgui/imgui.h"
#include "../imgui/implot.h"
#include "../imgui/implot_internal.h"

namespace ui {
	void init(LPDIRECT3DDEVICE9);
	void render();
}

namespace ui {
	inline LPDIRECT3DDEVICE9 dev;
	inline const char* window_title = "Analisi Empirica";
}

namespace ui {
	inline ImVec2 screen_res{ 000, 000 };
	inline ImVec2 window_pos{ 0, 0 };
	inline ImVec2 window_size{ 400, 300 };
	inline DWORD  window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
}