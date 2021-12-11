import { Point2, Rect } from '../../../index'

describe('[core] Rect', () => {
  describe('constructor', () => {
    it('initializes from empty constructor', () => {
      const rect = new Rect()

      expect(rect.x).toStrictEqual(0)
      expect(rect.y).toStrictEqual(0)
      expect(rect.width).toStrictEqual(0)
      expect(rect.height).toStrictEqual(0)
    })

    it('initializes from numbers', () => {
      const rect = new Rect(10, 20, 30, 40)

      expect(rect.x).toStrictEqual(10)
      expect(rect.y).toStrictEqual(20)
      expect(rect.width).toStrictEqual(30)
      expect(rect.height).toStrictEqual(40)
    })

    it('should update instance properties', () => {
      const rect = new Rect(10, 20, 30, 40)

      rect.x = 99
      rect.y = 88
      rect.width = 77
      rect.height = 66

      expect(rect.x).toStrictEqual(99)
      expect(rect.y).toStrictEqual(88)
      expect(rect.width).toStrictEqual(77)
      expect(rect.height).toStrictEqual(66)
    })
  })

  describe('methods', () => {
    describe('rescale', () => {
      it('rescales from int', () => {
        const rect = new Rect(0, 0, 100, 100)

        rect.rescale(2)

        expect(rect.x).toStrictEqual(0)
        expect(rect.y).toStrictEqual(0)
        expect(rect.width).toStrictEqual(200)
        expect(rect.height).toStrictEqual(200)
      })

      it('rescales from double', () => {
        const rect = new Rect(0, 0, 100, 100)

        rect.rescale(1.5)

        expect(rect.x).toStrictEqual(0)
        expect(rect.y).toStrictEqual(0)
        expect(rect.width).toStrictEqual(150)
        expect(rect.height).toStrictEqual(150)
      })

      it('rescales from double and rounds', () => {
        const rect = new Rect(0, 0, 33, 33)

        rect.rescale(1.5)

        expect(rect.x).toStrictEqual(0)
        expect(rect.y).toStrictEqual(0)
        expect(rect.width).toStrictEqual(49) // 49.5 -> 49
        expect(rect.height).toStrictEqual(49) // 49.5 -> 49
      })
    })

    describe('toSquare', () => {
      describe('when width is higher', () => {
        it('rescales to square', () => {
          const rect = new Rect(0, 0, 400, 200)

          rect.toSquare()

          expect(rect.x).toStrictEqual(0)
          expect(rect.y).toStrictEqual(0)
          expect(rect.width).toStrictEqual(400)
          expect(rect.height).toStrictEqual(400)
        })
      })

      describe('when height is higher', () => {
        it('rescales to square', () => {
          const rect = new Rect(0, 0, 100, 200)

          rect.toSquare()

          expect(rect.x).toStrictEqual(0)
          expect(rect.y).toStrictEqual(0)
          expect(rect.width).toStrictEqual(200)
          expect(rect.height).toStrictEqual(200)
        })
      })
    })
  })
})
