#include <gtest/gtest.h>
#include "car_builder.h"
#include "kia_parts_factory.h"
#include "hyundai_parts_factory.h"
#include "car.h"
#include <string>

class CarBuilderTest : public ::testing::Test {
protected:
    CarBuilderTest() {}
    void SetUp() override {}
    void TearDown() override {}
};

TEST(CarBuilderTest, BuildKiaCar) {
    const CarPartsFactory* kiaFactory = KiaPartsFactory::GetInstance();
    CarBuilder builder(kiaFactory);

    builder.CreateDoor().CreateWheel().CreateRoof().SetColor("Red");
    Car* kiaCar = builder.Build();

    std::string spec = kiaCar->GetSpec();
    EXPECT_EQ(spec, "Car([Kia][Door], [Kia][Wheel], [Kia][Roof], Red)");

    delete kiaCar;
}

TEST(CarBuilderTest, BuildKiaCar2) {
    const CarPartsFactory* kiaFactory = KiaPartsFactory::GetInstance();
    CarBuilder builder(kiaFactory);

    builder.CreateDoor().CreateWheel().CreateRoof().SetColor("Blue");
    Car* kiaCar = builder.Build();

    std::string spec = kiaCar->GetSpec();
    EXPECT_EQ(spec, "Car([Kia][Door], [Kia][Wheel], [Kia][Roof], Blue)");

    delete kiaCar;
}

TEST(CarBuilderTest, BuildHyundaiCar) {
    const CarPartsFactory* hyundaiFactory = HyundaiPartsFactory::GetInstance();
    CarBuilder builder(hyundaiFactory);

    builder.CreateDoor().CreateWheel().CreateRoof().SetColor("Blue");
    Car* hyundaiCar = builder.Build();

    std::string spec = hyundaiCar->GetSpec();
    EXPECT_EQ(spec, "Car([Hyundai][Door], [Hyundai][Wheel], [Hyundai][Roof], Blue)");

    delete hyundaiCar;
}

TEST(CarBuilderTest, BuildHyundaiCar2) {
    const CarPartsFactory* hyundaiFactory = HyundaiPartsFactory::GetInstance();
    CarBuilder builder(hyundaiFactory);

    builder.CreateDoor().CreateWheel().CreateRoof().SetColor("White");
    Car* hyundaiCar = builder.Build();

    std::string spec = hyundaiCar->GetSpec();
    EXPECT_EQ(spec, "Car([Hyundai][Door], [Hyundai][Wheel], [Hyundai][Roof], White)");

    delete hyundaiCar;
}

TEST(CarBuilderTest, BuildPartialCar) {
    const CarPartsFactory* kiaFactory = KiaPartsFactory::GetInstance();
    CarBuilder builder(kiaFactory);

    builder.CreateDoor().SetColor("Green");
    Car* partialCar = builder.Build();

    std::string spec = partialCar->GetSpec();
    EXPECT_EQ(spec, "Car([Kia][Door], Green)");

    delete partialCar;
}

TEST(CarBuilderTest, CopyAndAssignmentTest) {
    const CarPartsFactory* hyundaiFactory = HyundaiPartsFactory::GetInstance();
    CarBuilder builder(hyundaiFactory);

    builder.CreateWheel().SetColor("Yellow");
    Car* originalCar = builder.Build();

    Car copiedCar(*originalCar);
    EXPECT_EQ(copiedCar.GetSpec(), originalCar->GetSpec());

    builder.CreateDoor().CreateRoof().SetColor("Black");
    Car* anotherCar = builder.Build();

    *anotherCar = *originalCar;
    EXPECT_EQ(anotherCar->GetSpec(), originalCar->GetSpec());

    delete originalCar;
    delete anotherCar;
}
