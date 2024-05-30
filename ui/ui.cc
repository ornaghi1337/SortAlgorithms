#include "ui.hh"

#include <ostream>
#include <iostream>

#include "../globals.hh"
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"

#include "../sort/sortAlg.h"

#define CHECKBOX_FLAG(flags, flag) ImGui::CheckboxFlags(#flag, (unsigned int*)&flags, flag)

void ui::render() {
    if (!globals.active) return;

    ImGui::SetNextWindowPos(ImVec2(window_pos.x, window_pos.y), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(window_size.x, window_size.y));
    ImGui::SetNextWindowBgAlpha(1.0f);

    ImGui::Begin(window_title, &globals.active, window_flags);
    {
		
		ImGui::InputInt("Dim Array", &globals.dimensioneArray, 100, 10000);
    	if(ImGui::Button("Ordina!", {100, 20}))
    	{
			
    		runSort(globals.insertionTime, globals.selectionTime, globals.bubbleTime, globals.mergeTime, globals.contaElementi);
			globals.contaElementi++;

    		


    	}
        ImGui::SameLine();
        if(ImGui::Button("Reset", {100, 20}))
		{
            resetArray(globals.insertionTime, globals.contaElementi);
            resetArray(globals.selectionTime, globals.contaElementi);
            resetArray(globals.bubbleTime, globals.contaElementi);
            resetArray(globals.mergeTime, globals.contaElementi);
			globals.contaElementi = 0;
		}
        ImGui::SameLine();

        if (ImGui::Button("Read from file", { 100, 20 })) {
            readFromFile(globals.insertionTime, globals.selectionTime, globals.bubbleTime, globals.mergeTime, &globals.contaElementi);
            
        }

        ImPlot::BeginPlot("Sort Time", "Dimensione Array (scala n Elementi)", "Tempo", {400, 230});

    	
    	ImPlot::PlotLine("Insertion Time", globals.insertionTime, globals.contaElementi);
    	ImPlot::PlotLine("Selection Time", globals.selectionTime, globals.contaElementi);
    	ImPlot::PlotLine("Bubble Time", globals.bubbleTime, globals.contaElementi);
    	ImPlot::PlotLine("Merge Time", globals.mergeTime, globals.contaElementi);
    	ImPlot::EndPlot();
        ImGui::SameLine();
    }
    ImGui::End();
}

void ui::init(LPDIRECT3DDEVICE9 device) {
    dev = device;
	
    
    ImGui::StyleColorsDark();

	if (window_pos.x == 0) {
		RECT screen_rect{};
		GetWindowRect(GetDesktopWindow(), &screen_rect);
		screen_res = ImVec2(float(screen_rect.right), float(screen_rect.bottom));
		window_pos = (screen_res - window_size) * 0.5f;

		
	}
}