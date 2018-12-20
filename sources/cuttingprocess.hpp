#ifndef CUTTINGPROCESS_HPP_INCLUDED
#define CUTTINGPROCESS_HPP_INCLUDED
#include <vector>
#include "headers.hpp"
#include "step.hpp"

class CuttingResult {
	private: std::string sequenceChain;
			 int platesCount, unusedSurfacesCount;
			 float unusedArea;

			 void setPlatesCount(int count);
			 void setUnusedSurfacesCount(int count);
			 void setUnusedArea(float area);
			 void setSequenceChain(std::string chain);

	public: void setResult(std::string chain, int platesCount, int unusedSurfaceCount, float area);
			bool operator<=(CuttingResult const& result); //worse or same
			bool operator<(CuttingResult const& result); //worse
			bool operator>=(CuttingResult const& result); //better or same
			bool operator>(CuttingResult const& result); //better
			bool operator==(CuttingResult const& result); //same

			std::string getSequenceChain();
			int getPlatesCount();
			int getUnusedSurfacesCount();
			float getUnusedArea();
};

class CuttingProcess {
	public: CuttingProcess(std::vector<std::shared_ptr<Form> > forms, std::vector<std::shared_ptr<Surface> > surfaces, SortMode sortMode);
			bool execute();
			std::vector<CuttingResult> results;
			SortMode getSortMode();
			void setSortMode(SortMode sortMode);
			Step * stepPosition = nullptr;
	private: SortMode sortMode;
			 void sortPlatesAndSurfaces();
};

#endif