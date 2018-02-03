class Paper():

    _publisher = "People's Daily"

    def reset_publisher(self):
        self._publisher = "Science Press"
        #Paper._publisher = "Science Press"
        
    @classmethod
    def change_publisher(cls, pub):
        cls._publisher = pub


if __name__ == "__main__":
    print("before change:", Paper._publisher)
    Paper.change_publisher("Guangming Daily")
    print("after change:", Paper._publisher)

    paper = Paper()
    paper.reset_publisher()
    print("after reset(Paper):", Paper._publisher)
    print("after reset(self):", paper._publisher)